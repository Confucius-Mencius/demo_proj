#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

. ${SCRIPT_PATH}/common.sh

function Pack
{
    BUILD_TYPE=$1
    PACK_CONF=$2

    if [ "${BUILD_TYPE}"x = "debug"x ]; then
        THIRD_PARTY_INSTALL_PREFIX=${THIRD_PARTY_INSTALL_PREFIX}/debug
        COMMON_COMPONENT_INSTALL_PREFIX=${COMMON_COMPONENT_INSTALL_PREFIX}/debug/lib
        OUTPUT_DIR=${SCRIPT_PATH}/output/debug
        BIN_DIR=${SCRIPT_PATH}/bin/debug
        TAR_DIR=${SCRIPT_PATH}/bin/tgz_debugs
        PACK_NAME=debug
    elif [ "${BUILD_TYPE}"x = "release"x ]; then
        THIRD_PARTY_INSTALL_PREFIX=${THIRD_PARTY_INSTALL_PREFIX}/release
        COMMON_COMPONENT_INSTALL_PREFIX=${COMMON_COMPONENT_INSTALL_PREFIX}/release/lib
        OUTPUT_DIR=${SCRIPT_PATH}/output/release
        BIN_DIR=${SCRIPT_PATH}/bin/release
        TAR_DIR=${SCRIPT_PATH}/bin/tgz_releases
        PACK_NAME=release
    else
        echo "invalid build type: ${BUILD_TYPE}"
        exit 1
    fi
    
    if [ ! -d ${BIN_DIR} ]; then
        mkdir -p ${BIN_DIR}
    fi

    PackThirdParties ${THIRD_PARTY_INSTALL_PREFIX} ${BIN_DIR} "${THIRD_PARTY_LIB_LIST[*]}"
    PackCommonComponents ${COMMON_COMPONENT_INSTALL_PREFIX} ${BIN_DIR}

    for i in ${PROJ_LIB_LIST[@]}; do
        LIB=$i
        PackLib ${OUTPUT_DIR} ${BIN_DIR} ${LIB}
    done

    for i in ${PROJ_SERVER_LIST[@]}; do
        SERVER=$i
        PackServer ${OUTPUT_DIR} ${BIN_DIR} ${SERVER}

        cd ${BIN_DIR}/${SERVER}
        ln -sf ../common_component/app_launcher ${BIN_DIR}/${SERVER}/${SERVER}
    done

    PackScripts ${SCRIPT_PATH}/../.. ${BIN_DIR}

    if [ ${PACK_CONF} -eq 1 ]; then
        PackConf ${SCRIPT_PATH}/../.. ${BIN_DIR}
    fi

    ###############################################################################
    # tar
    if [ ! -d ${TAR_DIR} ]; then
        mkdir -p ${TAR_DIR}
    fi

    TOTAL=$[${#PROJ_LIB_LIST[@]}+${#PROJ_SERVER_LIST[@]}+5]
    N=0
    Processbar $N ${TOTAL}

    cd ${BIN_DIR}/..
    tar -cf - ${PACK_NAME} --exclude=test --exclude *.log --exclude *.log.* --exclude *.*.log --exclude core-* --exclude *.pid --exclude *.lock --exclude mem_profiling.*.heap | pigz >${PACK_NAME}.tgz
    N=$[$N+1]; Processbar $N ${TOTAL}

    cd ${BIN_DIR}
    tar -cf - third_party | pigz >${TAR_DIR}/third_party.tgz
    N=$[$N+1]; Processbar $N ${TOTAL}

    tar -cf - common_component | pigz >${TAR_DIR}/common_component.tgz
    N=$[$N+1]; Processbar $N ${TOTAL}

    for i in ${PROJ_LIB_LIST[@]}; do
        LIB=$i
        tar -cf - ${LIB} --exclude=test | pigz >${TAR_DIR}/${LIB}.tgz
        N=$[$N+1]; Processbar $N ${TOTAL}
    done

    for i in ${PROJ_SERVER_LIST[@]}; do
        SERVER=$i
        tar -cf - ${SERVER} --exclude=test --exclude *.*.log --exclude core-* --exclude *.pid --exclude *.lock --exclude mem_profiling.*.heap | pigz >${TAR_DIR}/${SERVER}.tgz
        N=$[$N+1]; Processbar $N ${TOTAL}
    done

    tar -cf - scripts | pigz >${TAR_DIR}/scripts.tgz
    N=$[$N+1]; Processbar $N ${TOTAL}

    if [ -d conf ]; then
        tar -cf - conf | pigz >${TAR_DIR}/conf.tgz
    fi
    N=$[$N+1]; Processbar $N ${TOTAL}

    echo ""
}
