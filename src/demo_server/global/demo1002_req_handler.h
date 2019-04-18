#ifndef DEMO_SERVER_GLOBAL_DEMO1002_REQ_HANDLER_H_
#define DEMO_SERVER_GLOBAL_DEMO1002_REQ_HANDLER_H_

#include "msg_handler.h"

namespace global
{
class Demo1002ReqHandler : public MsgHandler
{
public:
    Demo1002ReqHandler();
    virtual ~Demo1002ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_GLOBAL_DEMO1002_REQ_HANDLER_H_
