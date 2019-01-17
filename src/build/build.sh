#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

# 编译完成后打包，是否打包配置文件。注意：打包配置文件将会覆盖bin目录下你修改过的配置文件！
PACK_CONF=1

if [ $# == 0 ]; then
    echo "usage: ${SCRIPT_PATH}/build.sh
         -h show this help info.
         -b debug|release build projects.
         -r debug|release rebuild projects.
         -c debug|release clear tmp files.
         -p debug|release pack projects."
    exit 1
fi


. ${SCRIPT_PATH}/../../../sh_tools/base/util.sh
. ${SCRIPT_PATH}/../../../sh_tools/base/proj_util.sh
. ${SCRIPT_PATH}/../../../sh_tools/base/pack_util.sh
. ${SCRIPT_PATH}/pack.sh


while getopts "b:c:r:p:h" opt; do
    case $opt in
        h)
            echo "usage: ${SCRIPT_PATH}/build.sh
                 -h show this help info.
                 -b debug|release build projects.
                 -r debug|release rebuild projects.
                 -c debug|release clear tmp files.
                 -p debug|release pack projects."
        ;;
        b)
            if [ "${OPTARG}"x = "debug"x ]; then
                INSTALL_PREFIX=${INSTALL_PREFIX}/debug
                OUTPUT_DIR=${SCRIPT_PATH}/output/debug
                BUILD_PARENT_DIR=${SCRIPT_PATH}/cmake/debug
                BUILD_TYPE=Debug
            elif [ "${OPTARG}"x = "release"x ]; then
                INSTALL_PREFIX=${INSTALL_PREFIX}/release
                OUTPUT_DIR=${SCRIPT_PATH}/output/release
                BUILD_PARENT_DIR=${SCRIPT_PATH}/cmake/release
                BUILD_TYPE=Release
            else
                echo "invalid build type: ${OPTARG}"
                exit 1
            fi
            
            MakeDir ${OUTPUT_DIR}

            ###############################################################################
            for i in ${PROJ_LIST[@]}; do
                PROJ=$i

                cd ${CODE_BASE_DIR}
                BuildProj ${PROJ} ${SCRIPT_PATH}/../${PROJ} ${BUILD_PARENT_DIR}/${PROJ} ${BUILD_TYPE} ${INSTALL_PREFIX}
								
                # cd ${CODE_BASE_DIR}
                # InstallProj ${PROJ} ${BUILD_PARENT_DIR}/${PROJ}
            done

            Pack ${OPTARG} ${PACK_CONF}
        ;;
        r)
            if [ "${OPTARG}"x = "debug"x ]; then
                INSTALL_PREFIX=${INSTALL_PREFIX}/debug
                OUTPUT_DIR=${SCRIPT_PATH}/output/debug
                BUILD_PARENT_DIR=${SCRIPT_PATH}/cmake/debug
                BUILD_TYPE=Debug
            elif [ "${OPTARG}"x = "release"x ]; then
                INSTALL_PREFIX=${INSTALL_PREFIX}/release
                OUTPUT_DIR=${SCRIPT_PATH}/output/release
                BUILD_PARENT_DIR=${SCRIPT_PATH}/cmake/release
                BUILD_TYPE=Release
            else
                echo "invalid rebuild type: ${OPTARG}"
                exit 1
            fi
            
            MakeDir ${OUTPUT_DIR}

            ###############################################################################
            for i in ${PROJ_LIST[@]}; do
                PROJ=$i

                cd ${CODE_BASE_DIR}
                RebuildProj ${PROJ} ${SCRIPT_PATH}/../${PROJ} ${BUILD_PARENT_DIR}/${PROJ} ${BUILD_TYPE} ${INSTALL_PREFIX}

                # cd ${CODE_BASE_DIR}
                # InstallProj ${PROJ} ${BUILD_PARENT_DIR}/${PROJ}
            done

            Pack ${OPTARG} ${PACK_CONF}
        ;;
        c)
            if [ "${OPTARG}"x = "debug"x ]; then
                BUILD_PARENT_DIR=${SCRIPT_PATH}/cmake/debug
            elif [ "${OPTARG}"x = "release"x ]; then
                BUILD_PARENT_DIR=${SCRIPT_PATH}/cmake/release
            else
                echo "invalid clear type: ${OPTARG}"
                exit 1
            fi

            ###############################################################################
            for i in ${PROJ_LIST[@]}; do
                PROJ=$i
                cd ${CODE_BASE_DIR}
                ClearProj ${PROJ} ${BUILD_PARENT_DIR}/${PROJ}
            done
        ;;
        p)
            if [ "${OPTARG}"x = "debug"x -o "${OPTARG}"x = "release"x ]; then
                Pack ${OPTARG} ${PACK_CONF}
            else
                echo "invalid build type: ${OPTARG}"
                exit 1
            fi
        ;;
        \?)
            echo "invalid option"
        ;;
    esac
done
