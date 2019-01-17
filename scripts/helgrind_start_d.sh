#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 多线程竞态检查

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

VALGRIND_PARAMS="--tool=helgrind -v"

function StartServer
{
    SERVER=$1
    valgrind ${VALGRIND_PARAMS} --log-file=./${SERVER}.helgrind.log ./${SERVER} -log_conf_file_path=../conf/${SERVER}_log_conf.properties -logger_name=${SERVER} -app_conf_file_path=../conf/${SERVER}_conf.xml -common_component_dir=${COMMON_COMPONENT_DIR} -daemon=true -chdir_to_root=false
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

# 程序执行结束后，查看demo_server.helgrind.log文件。
# 搜索关键字：Possible data race，a thread error detector，Attempt to re-lock a non-recursive lock I already hold，Lock was previously acquired，deadlock，violated


# 1) 资源不安全访问 【就是多个线程在没有同步的情况下写某个资源】
# 2) 死锁问题 
# 3) POSIX pthreads API的错误使用 
