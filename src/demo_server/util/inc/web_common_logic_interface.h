#ifndef DEMO_SERVER_UTIL_INC_WEB_COMMON_LOGIC_INTERFACE_H_
#define DEMO_SERVER_UTIL_INC_WEB_COMMON_LOGIC_INTERFACE_H_

#include "web_logic_interface.h"

// 线程内多个模块共享的逻辑，一般不需加锁

namespace tcp
{
namespace web
{
class TheCommonLogicInterface : public CommonLogicInterface
{
public:
    virtual ~TheCommonLogicInterface()
    {
    }
};
}
}

#endif // DEMO_SERVER_UTIL_INC_WEB_COMMON_LOGIC_INTERFACE_H_
