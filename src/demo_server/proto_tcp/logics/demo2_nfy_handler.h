#ifndef DEMO_SERVER_PROTO_TCP_LOGICS_DEMO2_NFY_HANDLER_H_
#define DEMO_SERVER_PROTO_TCP_LOGICS_DEMO2_NFY_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace proto
{
class Demo2NfyHandler : public MsgHandler
{
public:
    Demo2NfyHandler();
    virtual ~Demo2NfyHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}
}

#endif // DEMO_SERVER_PROTO_TCP_LOGICS_DEMO2_NFY_HANDLER_H_
