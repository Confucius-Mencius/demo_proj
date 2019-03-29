#ifndef DEMO_SERVER_UTIL_INC_WORK_COMMON_LOGIC_INTERFACE_H_
#define DEMO_SERVER_UTIL_INC_WORK_COMMON_LOGIC_INTERFACE_H_

#include "work_logic_interface.h"

// 线程内多个模块共享的逻辑，一般不需加锁

namespace work
{
class TheCommonLogicInterface : public CommonLogicInterface
{
public:
    virtual ~TheCommonLogicInterface()
    {
    }
};
}

#endif // DEMO_SERVER_UTIL_INC_WORK_COMMON_LOGIC_INTERFACE_H_
