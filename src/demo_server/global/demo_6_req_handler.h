#ifndef DEMO_SERVER_GLOBAL_DEMO_6_REQ_HANDLER_H_
#define DEMO_SERVER_GLOBAL_DEMO_6_REQ_HANDLER_H_

#include "msg_handler.h"

namespace global
{
class Demo6ReqHandler : public MsgHandler
{
public:
    Demo6ReqHandler();
    virtual ~Demo6ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_GLOBAL_DEMO_6_REQ_HANDLER_H_
