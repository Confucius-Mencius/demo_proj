#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# != 1 ]; then
    echo "Usage: ${SCRIPT_PATH}/cpuprofile_show.sh <callgrind file>"
    exit 0
fi

. ${SCRIPT_PATH}/common.sh

CALLGRIND_FILE=$1

kcachegrind ${CALLGRIND_FILE}
