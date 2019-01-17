#ifndef DEMO_SERVER_UDP_LOGICS_MSG_HANDLER_H_
#define DEMO_SERVER_UDP_LOGICS_MSG_HANDLER_H_

// 一般做一个MsgHandler的基类，放消息处理器公用的一些函数

#include "udp_msg_handler_interface.h"
#include "udp_scheduler_interface.h"

namespace udp
{
class Logic;

class MsgHandler : public MsgHandlerInterface
{
public:
    MsgHandler();
    virtual ~MsgHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    int Initialize(const void* ctx) override;

    void SetLogic(Logic* logic)
    {
        logic_ = logic;
    }

protected:
    Logic* logic_;
};
}

#endif // DEMO_SERVER_UDP_LOGICS_MSG_HANDLER_H_
