#ifndef DEMO_SERVER_UTIL_INC_BURDEN_LOCAL_LOGIC_INTERFACE_H_
#define DEMO_SERVER_UTIL_INC_BURDEN_LOCAL_LOGIC_INTERFACE_H_

#include "burden_logic_interface.h"

// 线程内多个模块共享的逻辑，一般不需加锁

namespace burden
{
class TheLocalLogicInterface : public LocalLogicInterface
{
public:
    virtual ~TheLocalLogicInterface()
    {
    }
};
}

#endif // DEMO_SERVER_UTIL_INC_BURDEN_LOCAL_LOGIC_INTERFACE_H_
