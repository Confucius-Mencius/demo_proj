#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

LOG_DIR=${SCRIPT_PATH}/..

if [ $# -gt 0 ]; then
    find ${LOG_DIR} -name "*.log*" | xargs tail -f | grep ERROR
else
    find ${LOG_DIR} -name "*.log*" | xargs more | grep ERROR
fi
