#ifndef DEMO_SERVER_GLOBAL_MSG_HANDLER_H_
#define DEMO_SERVER_GLOBAL_MSG_HANDLER_H_

// 一般做一个MsgHandler的基类，放消息处理器公用的一些函数

#include "global_msg_handler_interface.h"
#include "the_global_logic_interface.h"

namespace global
{
class MsgHandler : public MsgHandlerInterface
{
public:
    MsgHandler();
    virtual ~MsgHandler();

    void SetGlobalLogic(TheLogicInterface* global_logic)
    {
        global_logic_ = global_logic;
    }

protected:
    TheLogicInterface* global_logic_;
};
}

#endif // DEMO_SERVER_GLOBAL_MSG_HANDLER_H_
