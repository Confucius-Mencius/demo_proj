#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

function MySleep()
{
    typeset -i n=0
    while [ $n -le $1 ]; do
        n=$n+1
    done
}

for i in ${STOP_SERVER_LIST[@]}; do
    SERVER=$i
    cd ${BIN_DIR}/${SERVER}

    if [ ! -f "./${SERVER}.pid" ]; then
        continue
    fi

    PID=`cat ./${SERVER}.pid`
    n=`ps --no-heading ${PID} | wc -l`

    if [ $n == 0 ]; then
        continue
    fi

    read -p "Want to stop ${SERVER}? [Y/n]" INPUT
    echo ${INPUT}

    if [ ${INPUT} = "Y" -o ${INPUT} = "y" ]; then
        kill -3 ${PID}

        while [ $n != 0 ]; do
            MySleep 100
            n=`ps --no-heading ${PID} | wc -l`
        done

        echo "${SERVER} exit ok"
    fi
done
