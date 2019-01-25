#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 性能剖析，需要打开配置文件中的enable_cpu_profiling配置项。
# 参见官方文档：https://github.com/gperftools/gperftools/wiki

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

export PPROF_PATH=/opt/third_party/release/gperftools/bin/pprof

function StartServer()
{
    SERVER=$1
    ./${SERVER} -log_conf_file_path=../conf/${SERVER}_log_conf.properties -logger_name=${SERVER} -app_conf_file_path=../conf/${SERVER}_conf.xml -common_component_dir=${COMMON_COMPONENT_DIR} -daemon=true -chdir_to_root=false
}

for i in ${START_SERVER_LIST[@]}; do
    SERVER=$i
    export LD_LIBRARY_PATH=${BIN_DIR}/${SERVER}:${MY_LD_LIBRARY_PATH}

    cd ${BIN_DIR}/${SERVER}
    
    if [ -f "./${SERVER}.pid" ]; then
        PID=`cat ./${SERVER}.pid`
        n=`ps --no-heading ${PID} | wc -l`

        if [ $n != 0 ]; then
            echo "${SERVER}(${PID}) already running"
            continue
        else
            ulimit -c unlimited
            StartServer ${SERVER}
        fi
    else
        ulimit -c unlimited
        StartServer ${SERVER}
    fi
done

# 程序执行结束后，会在程序目录下生成demo_server.prof文件，使用pprof分析，命令如下： pprof --text ./demo_server ./cpu_profiling.prof > performance.txt, 
# 从performance.txt文件中我们可以看到程序的CPU消耗从而对性能进行分析。
