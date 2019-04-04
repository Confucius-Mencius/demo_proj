#ifndef DEMO_SERVER_PROTO_TCP_LOGICS_DEMO8_REQ_HANDLER_H_
#define DEMO_SERVER_PROTO_TCP_LOGICS_DEMO8_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace proto
{
class Demo8ReqHandler : public MsgHandler
{
public:
    Demo8ReqHandler();
    virtual ~Demo8ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}
}

#endif // DEMO_SERVER_PROTO_TCP_LOGICS_DEMO8_REQ_HANDLER_H_
