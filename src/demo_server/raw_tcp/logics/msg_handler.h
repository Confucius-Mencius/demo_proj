#ifndef DEMO_SERVER_RAW_TCP_LOGICS_MSG_HANDLER_H_
#define DEMO_SERVER_RAW_TCP_LOGICS_MSG_HANDLER_H_

// 一般做一个MsgHandler的基类，放消息处理器公用的一些函数

#include "raw_tcp_common_logic_interface.h"
#include "raw_tcp_msg_handler_interface.h"
#include "the_global_logic_interface.h"

namespace tcp
{
namespace raw
{
class Logic;

class MsgHandler : public MsgHandlerInterface
{
public:
    MsgHandler();
    virtual ~MsgHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    int Initialize(const void* ctx) override;

    void SetGlobalLogic(global::TheLogicInterface* global_logic)
    {
        global_logic_ = global_logic;
    }

    void SetLogic(Logic* logic)
    {
        logic_ = logic;
    }

protected:
    global::TheLogicInterface* global_logic_;
    TheCommonLogicInterface* common_logic_;
    Logic* logic_;
};
}
}

#endif // DEMO_SERVER_RAW_TCP_LOGICS_MSG_HANDLER_H_
