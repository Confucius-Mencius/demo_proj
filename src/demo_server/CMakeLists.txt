###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

cmake_minimum_required(VERSION 2.8)

###############################################################################
# project name
set(PROJ_NAME demo_server)
project(${PROJ_NAME} CXX)

set(CXX_LANGUAGE on CACHE INTERNAL "this is a cxx language project")

###############################################################################
# third party
set(THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/../third_party)
include(${THIRD_PARTY_DIR}/cmake/third_party.cmake)
include(${THIRD_PARTY_DIR}/cmake/common_component.cmake)

###############################################################################
# 启用-Werror
SetCompileFlags(TRUE)

###############################################################################
# output dir
SetOutputDir(${PROJECT_SOURCE_DIR}/../build/output ${PROJ_NAME})

###############################################################################
# 打印编译选项
ShowBuildOptions()

# proto lib
set(PROTO_LIB_NAME proto)
set(PROTO_INC_DIR ${PROJECT_SOURCE_DIR}/../${PROTO_LIB_NAME}/src)
set(PROTO_LIB_DIR ${OUTPUT_DIR}/../${PROTO_LIB_NAME})

# common util lib
set(COMMON_UTIL_LIB_NAME common_util)
set(COMMON_UTIL_INC_DIR ${PROJECT_SOURCE_DIR}/../${COMMON_UTIL_LIB_NAME}/inc)
set(COMMON_UTIL_LIB_DIR ${OUTPUT_DIR}/../${COMMON_UTIL_LIB_NAME})

# proj util lib
set(UTIL_LIB_NAME util)

# proj inc dir
set(PROJ_INC_DIR ${PROJECT_SOURCE_DIR}/${UTIL_LIB_NAME}/inc)

###############################################################################
# sub dir
add_subdirectory(util)
add_subdirectory(global)
add_subdirectory(work)
add_subdirectory(burden)
add_subdirectory(raw_tcp)
add_subdirectory(proto_tcp)
add_subdirectory(http_ws)
add_subdirectory(test)
