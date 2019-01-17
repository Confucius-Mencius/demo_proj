#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 函数调用关系分析，有针对性地对调用次数较多且耗时的函数进行优化，有助于提高程序性能

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

VALGRIND_PARAMS="--tool=callgrind -v"
# VALGRIND_PARAMS="--tool=callgrind --separate-threads=yes -v"

function StartServer
{
    SERVER=$1
    valgrind ${VALGRIND_PARAMS} --log-file=./${SERVER}.callgrind.log ./${SERVER} -log_conf_file_path=../conf/${SERVER}_log_conf.properties -logger_name=${SERVER} -app_conf_file_path=../conf/${SERVER}_conf.xml -common_component_dir=${COMMON_COMPONENT_DIR} -daemon=true -chdir_to_root=false
}

for i in ${START_SERVER_LIST[@]}; do
    SERVER=${i}
    export LD_LIBRARY_PATH=${BIN_DIR}/${SERVER}:${MY_LD_LIBRARY_PATH}

    cd ${BIN_DIR}/${SERVER}
    
    if [[ -f "./${SERVER}.pid" ]]; then
        PID=`cat ./${SERVER}.pid`
        n=`ps --no-heading ${PID} | wc -l`

        if [[ ${n} != 0 ]]; then
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

# 程序执行结束后，会在程序目录下生成callgrind.out.pid，使用kcachegrind打开生成的callgrind.out.pid文件了解相互调用关系，分析哪个函数执行慢。
# 如果加上参数 -separate-threads=yes，就会为每个线程单独生成一个性能分析文件。