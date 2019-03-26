###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

cmake_minimum_required(VERSION 2.8)

###############################################################################
# project name
set(PROJ_NAME proto)
project(${PROJ_NAME} CXX)

set(CXX_LANGUAGE on CACHE INTERNAL "this is a cxx language project")

###############################################################################
# third party
set(THIRD_PARTY_DIR ${PROJECT_SOURCE_DIR}/../third_party)
include(${THIRD_PARTY_DIR}/cmake/third_party.cmake)

###############################################################################
# 启用-Werror
SetCompileFlags(FLASE)

###############################################################################
# output dir
SetOutputDir(${PROJECT_SOURCE_DIR}/../build/output ${PROJ_NAME})

###############################################################################
# 打印编译选项
ShowBuildOptions()

###############################################################################
# generate protobuf cpp/py/java code
set(PROTOC ${PROTOBUF_BIN_DIR}/${PROTOBUF_BIN_NAME})
set(CPP_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/src)
set(CPP_OUTPUT_TMP_DIR ${PROJECT_SOURCE_DIR}/tmp)
set(PY_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/py)
set(JAVA_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/java)

set(PROTO_DIR com/moon/demo/proto)
set(PROTO_FILE_LIST common.proto cs_msg_id.proto cs_msg.proto ss_msg_id.proto ss_msg.proto)

file(REMOVE_RECURSE ${CPP_OUTPUT_TMP_DIR})
file(MAKE_DIRECTORY ${CPP_OUTPUT_TMP_DIR})

file(REMOVE_RECURSE ${PY_OUTPUT_DIR})
file(MAKE_DIRECTORY ${PY_OUTPUT_DIR})

file(REMOVE_RECURSE ${JAVA_OUTPUT_DIR})
file(MAKE_DIRECTORY ${JAVA_OUTPUT_DIR})

foreach (PROTO_FILE ${PROTO_FILE_LIST})
    execute_process(COMMAND ${PROTOC} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --cpp_out=${CPP_OUTPUT_TMP_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE})
    execute_process(COMMAND ${PROTOC} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --python_out=${PY_OUTPUT_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE})
    execute_process(COMMAND ${PROTOC} --proto_path=${CMAKE_CURRENT_SOURCE_DIR} --java_out=${JAVA_OUTPUT_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${PROTO_FILE})
endforeach ()

###############################################################################
# 比较文件的MD5
set(CPP_PROTO_FILE_LIST common.pb.h common.pb.cc
        cs_msg_id.pb.h cs_msg_id.pb.cc cs_msg.pb.h cs_msg.pb.cc
        ss_msg_id.pb.h ss_msg_id.pb.cc ss_msg.pb.h ss_msg.pb.cc)

foreach (CPP_PROTO_FILE ${CPP_PROTO_FILE_LIST})
    if (NOT EXISTS ${CPP_OUTPUT_DIR}/${CPP_PROTO_FILE})
        execute_process(COMMAND cp ${CPP_OUTPUT_TMP_DIR}/${CPP_PROTO_FILE} ${CPP_OUTPUT_DIR})
    else ()
        file(MD5 ${CPP_OUTPUT_DIR}/${CPP_PROTO_FILE} OLD_MD5)
        file(MD5 ${CPP_OUTPUT_TMP_DIR}/${CPP_PROTO_FILE} NEW_MD5)

        if (NOT (${NEW_MD5} STREQUAL ${OLD_MD5}))
            execute_process(COMMAND cp -f ${CPP_OUTPUT_TMP_DIR}/${CPP_PROTO_FILE} ${CPP_OUTPUT_DIR})
        endif ()
    endif ()
endforeach ()

###############################################################################
# set py test proto dir and copy py proto files to it
set(PY_TEST_PROTO_CS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../py_test/${PROTO_DIR}/cs)
set(PY_PROTO_CS_FILE_LIST common_pb2.py cs_msg_id_pb2.py cs_msg_pb2.py)

if (NOT EXISTS ${PY_TEST_PROTO_CS_DIR})
    file(MAKE_DIRECTORY ${PY_TEST_PROTO_CS_DIR})
endif ()

foreach (PY_PROTO_CS_FILE ${PY_PROTO_CS_FILE_LIST})
    execute_process(COMMAND cp -f ${PY_OUTPUT_DIR}/${PY_PROTO_CS_FILE} ${PY_TEST_PROTO_CS_DIR})
endforeach ()

###############################################################################
# sub dir
add_subdirectory(src)
