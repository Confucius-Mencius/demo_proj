#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

find ${SCRIPT_PATH}/.. -name "my_app.lock" | xargs rm -rf
find ${SCRIPT_PATH}/.. -name "my_app.log*" | xargs rm -rf
