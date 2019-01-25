#!/bin/bash

###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

SCRIPT_PATH=$(cd `dirname $0`; pwd)

if [ $# != 1 ]; then
    echo "Usage: ${SCRIPT_PATH}/cpuprofile_show.sh PROF_FILE"
    exit 0
fi

. ${SCRIPT_PATH}/common.sh

export PPROF_PATH=/opt/third_party/release/gperftools/bin/pprof

SERVER=demo_server
PROF_FILE=$1

cd ${BIN_DIR}/${SERVER}
${PPROF_PATH} --lib_prefix=${BIN_DIR}/${SERVER}:${THIRD_PARTY_LIB_DIR} --text ./${SERVER} ./${PROF_FILE} > ${WORK_DIR}/performance.txt

# 从performance.txt文件中我们可以看到程序的CPU消耗从而对性能进行分析。

# Analyzing Text Output
# Text mode has lines of output that look like this:
#        14   2.1%  17.2%       58   8.7% std::_Rb_tree::find  
# Here is how to interpret the columns:
# Number of profiling samples in this function
# Percentage of profiling samples in this function
# Percentage of profiling samples in the functions printed so far
# Number of profiling samples in this function and its callees
# Percentage of profiling samples in this function and its callees
# Function name

使用

http://google-perftools.googlecode.com/svn/trunk/doc/cpuprofile.html 将了使用的方法
在代码link过程中添加参数 –lprofiler

1、直接调用提供的api：
这种方式比较适用于对于程序的某个局部来做分析的情况，直接在要做分析的局部调用相关的api即可。
方式：#include <gperftools/profiler.h>， 并调用函数：ProfilerStart() and ProfilerStop() 开始和结束


2、使用环境变量
运行程序：env CPUPROFILE=./helloworld.prof ./helloworld
指定要profile的程序为helloworld，并且指定产生的分析结果文件的路径为./helloworld.prof

如果是多线程，则在线程的开始处调用 ProfilerRegisterThread()

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++

结果分析

我们可以通过pprof生成 text，pdf等各种形式的输出

如 pprof --text ./program prog.prof  > prog.txt

pprof --pdf ./program  prog.prof > prog.pdf

其中 program 是应用程序

如果想生存pdf的格式必须要安装 ghostscript 和 graphviz 两个库


Text mode has lines of output that look like this:

       14   2.1%  17.2%       58   8.7% std::_Rb_tree::find
Here is how to interpret the columns:

Number of profiling samples in this function  分析样本数量（不包含其他函数调用）
Percentage of profiling samples in this function  分析样本百分比（不包含其他函数调用）
Percentage of profiling samples in the functions printed so far  目前为止的分析样本百分比（不包含其他函数调用）
Number of profiling samples in this function and its callees  分析样本数量（包含其他函数调用）
Percentage of profiling samples in this function and its callees  分析样本百分比（包含其他函数调用）
Function name  函数名
含义如下：
14：find函数花费了14个profiling samples
2.1%：find函数花费的profiling samples占总的profiling samples的比例
17.2%：到find函数为止，已经运行的函数占总的profiling samples的比例
58：find函数加上find函数里的被调用者总共花费的profiling samples
8.7%：find函数加上find函数里的被调用者总共花费的profiling samples占总的profiling samples的比例
std::_Rb_tree::find：表示profile的函数
注意： 默认是 100 samples a second，所以得出的结果除以100，得秒单位，即 find函数本身花费了0.14秒， 而包含内部的其他调用之后花费了 0.58秒


关于图形风格输出结果
1.节点
每个节点代表一个函数，节点数据格式：
Class Name
Method Name
local (percentage)
of cumulative (percentage)
  
local时间是函数直接执行的指令所消耗的CPU时间（包括内联函数）；性能分析通过抽样方法完成，默认是1秒100个样本，一个样本是10毫秒，即时间单位是10毫秒；
cumulative时间是local时间与其他函数调用的总和；
如果cumulative时间与local时间相同，则不打印cumulative时间项。
2.有向边
调用者指向被调用者，有向边上的时间表示被调用者所消耗的CPU时间

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

注意：

要用google-perftool来分析程序，必须保证程序能正常退出。

# 一般好的程序， 时间片分布非常均匀，基本上看第二列， 就知道热点在哪里了
