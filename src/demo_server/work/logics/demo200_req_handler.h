#ifndef DEMO_SERVER_WORK_LOGICS_DEMO200_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO200_REQ_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class Demo200ReqHandler : public MsgHandler
{
public:
    Demo200ReqHandler();
    virtual ~Demo200ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;

private:
    void SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO200_REQ_HANDLER_H_
