#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

TEST_CASE_DIR=(base tcp udp)

for i in ${TEST_CASE_DIR[@]}; do
    DIR=${SCRIPT_PATH}/../test_case/$i

    for f in ${DIR}/*.py; do
        # nosetests -v -s $f
        nosetests -v $f
    done
done

cd ${SCRIPT_PATH}
