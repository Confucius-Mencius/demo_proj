#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# != 1 ]; then
    echo "Usage: ${SCRIPT_PATH}/cpuprofile_show.sh <massif file>"
    exit 0
fi

. ${SCRIPT_PATH}/common.sh

MASSIF_FILE=$1

ms_print ${MASSIF_FILE}

# 结果如果比较多，可以重定向到文件中查看。
