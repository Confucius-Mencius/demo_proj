#ifndef DEMO_SERVER_UTIL_INC_PROTO_TCP_COMMON_LOGIC_INTERFACE_H_
#define DEMO_SERVER_UTIL_INC_PROTO_TCP_COMMON_LOGIC_INTERFACE_H_

#include "proto_tcp_logic_interface.h"

// 线程内多个模块共享的逻辑，一般不需加锁

namespace tcp
{
namespace proto
{
class TheCommonLogicInterface : public CommonLogicInterface
{
public:
    virtual ~TheCommonLogicInterface()
    {
    }

    virtual int StartSendNfyTimer(const ConnGUID* conn_guid) = 0;
};
}
}

#endif // DEMO_SERVER_UTIL_INC_PROTO_TCP_COMMON_LOGIC_INTERFACE_H_
