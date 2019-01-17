#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

for i in ${START_SERVER_LIST[@]}; do
    SERVER=${i}
    cd ${BIN_DIR}/${SERVER}

    if [[ ! -f "./${SERVER}.pid" ]]; then
        continue
    fi

    PID=`cat ./${SERVER}.pid`
    n=`ps --no-heading ${PID} | wc -l`

    if [[ ${n} == 0 ]]; then
        continue
    fi

    kill -1 ${PID}
    echo "send reload signal to ${SERVER} ok"
done
