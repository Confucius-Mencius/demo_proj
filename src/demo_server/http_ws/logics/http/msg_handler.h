#ifndef DEMO_SERVER_HTTP_WS_LOGICS_HTTP_MSG_HANDLER_H_
#define DEMO_SERVER_HTTP_WS_LOGICS_HTTP_MSG_HANDLER_H_

// 一般做一个MsgHandler的基类，放消息处理器公用的一些函数

#include "http_msg_handler_interface.h"
#include "http_ws_common_logic_interface.h"
#include "the_global_logic_interface.h"

namespace tcp
{
namespace http_ws
{
class Logic;
}

namespace http
{
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

    void SetLogic(tcp::http_ws::Logic* logic)
    {
        logic_ = logic;
    }

protected:
    global::TheLogicInterface* global_logic_;
    tcp::http_ws::TheCommonLogicInterface* common_logic_;
    tcp::http_ws::Logic* logic_;
};
}
}

#endif // DEMO_SERVER_HTTP_WS_LOGICS_HTTP_MSG_HANDLER_H_
