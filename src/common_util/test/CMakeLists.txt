###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

set(PROJ_SRC_DIR ${PROJECT_SOURCE_DIR}/src)

set(TEST_NAME ${PROJ_NAME}_test)
set(EXE_NAME ${TEST_NAME})

###############################################################################
# include/link dir
include_directories(${PROJ_INC_DIR} ${PROJ_SRC_DIR} ${COMMON_COMPONENT_INC_DIR} ${LOG4CPLUS_INC_DIR} ${GTEST_INC_DIR})
link_directories(${COMMON_COMPONENT_LIB_DIR} ${LOG4CPLUS_LIB_DIR} ${GTEST_LIB_DIR} ${GPERFTOOLS_LIB_DIR})

###############################################################################
# target and linked library
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${PROJ_INC_DIR}/*.h)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CUR_DIR_SRCS)
add_executable(${EXE_NAME} ${HEADERS} ${CUR_DIR_SRCS})

target_link_libraries(${EXE_NAME} ${PROJ_NAME} ${COMMON_COMPONENT_LIB_NAME} ${LOG4CPLUS_LIB_NAME}
        ${GTEST_LIB_NAME} pthread ${GPERFTOOLS_LIB_NAME})

###############################################################################
# output dir
set(TEST_OUTPUT_DIR ${OUTPUT_DIR}/test)
MakeDir(${TEST_OUTPUT_DIR})

set_target_properties(${EXE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TEST_OUTPUT_DIR})

###############################################################################
# add test
add_test(NAME ${TEST_NAME} WORKING_DIRECTORY ${TEST_OUTPUT_DIR} COMMAND ${EXE_NAME} ${GTEST_EXE_OPTS}${TEST_NAME}.xml)
