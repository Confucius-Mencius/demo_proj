#ifndef DEMO_SERVER_BURDEN_LOGICS_DEMO_1_REQ_HANDLER_H_
#define DEMO_SERVER_BURDEN_LOGICS_DEMO_1_REQ_HANDLER_H_

#include "msg_handler.h"

namespace burden
{
class Demo1ReqHandler : public MsgHandler
{
public:
    Demo1ReqHandler();
    virtual ~Demo1ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_BURDEN_LOGICS_DEMO_1_REQ_HANDLER_H_
