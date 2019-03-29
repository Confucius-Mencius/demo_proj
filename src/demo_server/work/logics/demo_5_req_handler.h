#ifndef DEMO_SERVER_WORK_LOGICS_DEMO_5_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO_5_REQ_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class Demo5ReqHandler : public MsgHandler
{
public:
    Demo5ReqHandler();
    virtual ~Demo5ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    MsgId GetMsgId() override;
    void OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
               size_t msg_body_len) override;

private:
    void SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO_5_REQ_HANDLER_H_
