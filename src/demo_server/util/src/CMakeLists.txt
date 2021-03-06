###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

set(LIB_NAME ${UTIL_LIB_NAME})

###############################################################################
# lib version
set(BUILD_VERSION 1.0.0)

###############################################################################
# include/link dir
include_directories(${PROJ_INC_DIR} ${COMMON_COMPONENT_INC_DIR} ${LOG4CPLUS_INC_DIR}
        ${GPERFTOOLS_INC_DIR})
link_directories(${COMMON_COMPONENT_LIB_DIR} ${GPERFTOOLS_LIB_DIR})

###############################################################################
# target
file(GLOB HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${PROJ_INC_DIR}/*.h)
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} CUR_DIR_SRCS)
add_library(${LIB_NAME} SHARED ${HEADERS} ${CUR_DIR_SRCS})

###############################################################################
# library dependence
target_link_libraries(${LIB_NAME} ${BASE_LIB_NAME} ${GPERFTOOLS_LIB_NAME})

###############################################################################
# output dir
set_target_properties(${LIB_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR})

###############################################################################
# version
set_target_properties(${LIB_NAME} PROPERTIES VERSION ${BUILD_VERSION} SOVERSION 1)
