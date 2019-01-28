#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# != 2 ]; then
    echo "Usage: ${SCRIPT_PATH}/heapcheck_show.sh <server> <heap file>"
    exit 0
fi

. ${SCRIPT_PATH}/common.sh

export PPROF_PATH=/opt/third_party/release/gperftools/bin/pprof

SERVER=$1
HEAP_FILE=$2

# SERVER=${SCRIPT_PATH}/../demo_server/demo_server
# HEAP_FILE="/tmp/demo_server.7917._main_-end.heap"

${PPROF_PATH} --lib_prefix=${BIN_DIR}/${SERVER}:${MY_LD_LIBRARY_PATH} ${SERVER} ${HEAP_FILE} --inuse_objects --lines --heapcheck  --edgefraction=1e-10 --nodefraction=1e-10 --text
