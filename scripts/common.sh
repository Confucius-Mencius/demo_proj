#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

BIN_DIR=${SCRIPT_PATH}/..
THIRD_PARTY_LIB_DIR=${BIN_DIR}/third_party
COMMON_COMPONENT_DIR=${BIN_DIR}/common_component
PROTO_DIR=${BIN_DIR}/proto
COMMON_UTIL_DIR=${BIN_DIR}/common_util

MY_LD_LIBRARY_PATH=${COMMON_COMPONENT_DIR}:${THIRD_PARTY_LIB_DIR}
START_SERVER_LIST='demo_server'
TOP_SERVER_LIST='demo_server'
STOP_SERVER_LIST='demo_server'
