#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 缓存和分支预测分析，有针对性地对命中率较低的代码进行优化，有助于提高程序性能

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

VALGRIND_PARAMS="--tool=cachegrind -v"

function StartServer()
{
    SERVER=$1
    valgrind ${VALGRIND_PARAMS} --log-file=./${SERVER}.cachegrind.log ./${SERVER} -log_conf_file_path=../conf/${SERVER}_log_conf.properties -logger_name=${SERVER} -app_conf_file_path=../conf/${SERVER}_conf.xml -common_component_dir=${COMMON_COMPONENT_DIR} -daemon=true -chdir_to_root=false
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

# 程序执行结束后，会在程序目录下生成cachegrind.out.pid文件，使用cg_annotate解析生成的cachegrind.out.pid文件，命令如下：cg_annotate cachegrind.out.pid
# 也可以用kcachegrind打开。
