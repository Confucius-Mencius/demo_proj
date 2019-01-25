#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# != 1 ]; then
    echo "Usage: ${SCRIPT_PATH}/heapcheck_show.sh HEAP_FILE"
    exit 1
fi

. ${SCRIPT_PATH}/common.sh

export PPROF_PATH=/opt/third_party/release/gperftools/bin/pprof

SERVER=demo_server
HEAP_FILE="/tmp/demo_server.122382._main_-end.heap"

cd ${BIN_DIR}/${SERVER}
${PPROF_PATH} --lib_prefix=${BIN_DIR}/${SERVER}:${MY_LD_LIBRARY_PATH} ./${SERVER} ${HEAP_FILE} --inuse_objects --lines --heapcheck  --edgefraction=1e-10 --nodefraction=1e-10 --text
