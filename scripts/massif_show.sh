#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

SERVER=demo_server
MASSIF_FILE="massif.out.11055"

cd ${BIN_DIR}/${SERVER}
ms_print ./${MASSIF_FILE}

# 结果如果比较多，可以重定向到文件中查看。
