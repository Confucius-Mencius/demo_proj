#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

SERVER=demo_server
MASSIF_LOG_FILE="callgrind.out.12687"

cd ${BIN_DIR}/${SERVER}
kcachegrind ./${MASSIF_LOG_FILE}
