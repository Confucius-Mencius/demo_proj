#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 内存泄露检查
# 参见官方文档：https://github.com/gperftools/gperftools/wiki

SCRIPT_PATH=$(cd `dirname $0`; pwd)

. ${SCRIPT_PATH}/common.sh

export PPROF_PATH=/opt/third_party/release/gperftools/bin/pprof

function StartServer()
{
    SERVER=$1
    env HEAPCHECK=normal ./${SERVER} -log_conf_file_path=../conf/${SERVER}_log_conf.properties -logger_name=${SERVER} -app_conf_file_path=../conf/${SERVER}_conf.xml -common_component_dir=${COMMON_COMPONENT_DIR} -daemon=false -chdir_to_root=false
}

for i in ${START_SERVER_LIST[@]}; do
    SERVER=$i
    export LD_LIBRARY_PATH=${BIN_DIR}/${SERVER}:${MY_LD_LIBRARY_PATH}

    cd ${BIN_DIR}/${SERVER}
    
    if [ -f "./${SERVER}.pid" ]; then
        PID=`cat ./${SERVER}.pid`
        n=`ps --no-heading ${PID} | wc -l`

        if [ $n != 0 ]; then
            echo "${SERVER}(${PID}) already running"
            continue
        else
            ulimit -c unlimited
            StartServer ${SERVER}
        fi
    else
        ulimit -c unlimited
        StartServer ${SERVER}
    fi
done

# 以-daemon=false运行，程序执行结束后，会在终端输出很多信息，提示生成了一个.heap文件，可以使用pprof进行分析。
# 命令如下： pprof ./demo_server "/tmp/demo_server.109726._main_-end.heap" --inuse_objects --lines --heapcheck  --edgefraction=1e-10 --nodefraction=1e-10 --text (或者--gv)，使用--gv需要安装graphviz和gv。

# sudo apt-get install graphviz gv

# Output type:
#    --text              Generate text report
#    --stacks            Generate stack traces similar to the heap profiler (requires --text)
#    --callgrind         Generate callgrind format to stdout
#    --gv                Generate Postscript and display
#    --evince            Generate PDF and display
#    --web               Generate SVG and display
#    --list=<regexp>     Generate source listing of matching routines
#    --disasm=<regexp>   Generate disassembly of matching routines
#    --symbols           Print demangled symbol names found at given addresses
#    --dot               Generate DOT file to stdout
#    --ps                Generate Postcript to stdout
#    --pdf               Generate PDF to stdout
#    --svg               Generate SVG to stdout
#    --gif               Generate GIF to stdout
#    --raw               Generate symbolized pprof data (useful with remote fetch)

# 选项：
#  HEAP_PROFILE_ALLOCATION_INTERVAL
# 程序内存每增长这一数值之后就dump 一次内存，默认是1G （1073741824）

#  HEAP_PROFILE_INUSE_INTERVAL
# 程序如果一次性分配内存超过这个数值dump 默认是100K， 待验证
