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
    MsgId GetMsgId() override;
    void OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
               size_t msg_body_len) override;

private:
    void SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const;
};
}

#endif // DEMO_SERVER_BURDEN_LOGICS_DEMO_1_REQ_HANDLER_H_
