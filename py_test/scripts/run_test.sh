#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

TEST_CASE_DIR=(base tcp proto_tcp http ws)

for i in ${TEST_CASE_DIR[@]}; do
    DIR=${SCRIPT_PATH}/../test_case/$i

    for f in ${DIR}/*.py; do
        # -v: --verbose, Be more verbose.  -s: --nocapture, Don't capture stdout (any stdout output will be printed immediately).
        # nosetests -v -s --processes=-1 --process-timeout=10 --process-restartworker $f
        nosetests -v $f
    done
done

cd ${SCRIPT_PATH}
