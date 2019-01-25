#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# top里面按H键显示线程

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

PID_LIST=""

for i in ${TOP_SERVER_LIST[@]}; do
    SERVER=$i
    cd ${BIN_DIR}/${SERVER}

    if [ ! -f "./${SERVER}.pid" ]; then
        continue
    fi

    if [ "${PID_LIST}" = "" ]; then
        PID_LIST=`cat ./${SERVER}.pid`
    else
        PID_LIST=${PID_LIST}","`cat ./${SERVER}.pid`
    fi
done

if [ ${PID_LIST} != "" ]; then
    top -p ${PID_LIST}
fi
