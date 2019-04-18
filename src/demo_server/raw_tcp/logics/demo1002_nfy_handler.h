#ifndef DEMO_SERVER_RAW_TCP_LOGICS_DEMO1002_NFY_HANDLER_H_
#define DEMO_SERVER_RAW_TCP_LOGICS_DEMO1002_NFY_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace raw
{
class Demo1002NfyHandler : public MsgHandler
{
public:
    Demo1002NfyHandler();
    virtual ~Demo1002NfyHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}
}

#endif // DEMO_SERVER_RAW_TCP_LOGICS_DEMO1002_NFY_HANDLER_H_
