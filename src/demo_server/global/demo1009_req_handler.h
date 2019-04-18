#ifndef DEMO_SERVER_GLOBAL_DEMO1009_REQ_HANDLER_H_
#define DEMO_SERVER_GLOBAL_DEMO1009_REQ_HANDLER_H_

#include "msg_handler.h"

namespace global
{
class Demo1009ReqHandler : public MsgHandler
{
public:
    Demo1009ReqHandler();
    virtual ~Demo1009ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_GLOBAL_DEMO1009_REQ_HANDLER_H_
