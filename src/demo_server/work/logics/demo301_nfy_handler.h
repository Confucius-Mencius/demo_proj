#ifndef DEMO_SERVER_WORK_LOGICS_DEMO301_NFY_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO301_NFY_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class Demo301NfyHandler : public MsgHandler
{
public:
    Demo301NfyHandler();
    virtual ~Demo301NfyHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO301_NFY_HANDLER_H_
