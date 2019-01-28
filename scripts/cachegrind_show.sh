#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# != 1 ]; then
    echo "Usage: ${SCRIPT_PATH}/cpuprofile_show.sh <cachegrind file>"
    exit 0
fi

. ${SCRIPT_PATH}/common.sh

CACHEGRIND_FILE=$1

cg_annotate ${CACHEGRIND_FILE}
