#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 内存泄露检查

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

# VALGRIND_PARAMS="--tool=memcheck --leak-check=full --error-limit=no --track-origins=yes --trace-children=yes --track-fds=yes --show-reachable=yes --read-var-info=yes --gen-suppressions=all -v"
VALGRIND_PARAMS="--tool=memcheck --leak-check=full --error-limit=no --track-origins=yes --trace-children=yes --track-fds=yes --show-reachable=yes --read-var-info=yes -v"

function StartServer
{
    SERVER=$1
    valgrind ${VALGRIND_PARAMS} --suppressions=${SCRIPT_PATH}/valgrind.supp --log-file=./${SERVER}.memcheck.log ./${SERVER} -log_conf_file_path=../conf/${SERVER}_log_conf.properties -logger_name=${SERVER} -app_conf_file_path=../conf/${SERVER}_conf.xml -common_component_dir=${COMMON_COMPONENT_DIR} -daemon=true -chdir_to_root=false
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
