#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# -gt 0 ]; then
    # 命令行指定循环多少次，必须>=1
    LOOP=$1
    for ((i=1; i<=$LOOP; i++)); do
        ${SCRIPT_PATH}/run_test.sh
    done
else
    # 无限循环
    while [ 1 -eq 1 ]; do
        ${SCRIPT_PATH}/run_test.sh
    done
fi
