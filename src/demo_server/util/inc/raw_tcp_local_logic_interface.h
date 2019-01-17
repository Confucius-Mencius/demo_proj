#ifndef DEMO_SERVER_UTIL_INC_RAW_TCP_LOCAL_LOGIC_INTERFACE_H_
#define DEMO_SERVER_UTIL_INC_RAW_TCP_LOCAL_LOGIC_INTERFACE_H_

#include "tcp_logic_interface.h"

// 线程内多个模块共享的逻辑，一般不需加锁

namespace raw_tcp
{
class TheLocalLogicInterface : public tcp::LocalLogicInterface
{
public:
    virtual ~TheLocalLogicInterface()
    {
    }
};
}

#endif // DEMO_SERVER_UTIL_INC_TCP_LOCAL_LOGIC_INTERFACE_H_
