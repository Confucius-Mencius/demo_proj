#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

CODE_BASE_DIR=${SCRIPT_PATH}/..
INSTALL_PREFIX= # 实际并没有执行install，不用管这个目录

# third party安装目录，根据实际情况修改
THIRD_PARTY_INSTALL_PREFIX=/opt/third_party

# 依赖的第三方库，根据实际情况修改
THIRD_PARTY_LIB_LIST=(gflags zlib xz libxml2 log4cplus libevent libuuid openssl gperftools libunwind libwebsockets)

# common component安装目录，根据实际情况修改
COMMON_COMPONENT_INSTALL_PREFIX=/opt/common_component

# 项目自身的proj，根据实际情况修改
PROJ_LIST=(proto common_util demo_server) # 全部的proj列表
PROJ_LIB_LIST=(proto common_util) # lib列表，可执行程序除外
PROJ_SERVER_LIST=(demo_server) # 可执行程序列表，lib除外
