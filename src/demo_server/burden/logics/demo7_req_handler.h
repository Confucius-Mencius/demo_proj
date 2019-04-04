#ifndef DEMO_SERVER_BURDEN_LOGICS_DEMO7_REQ_HANDLER_H_
#define DEMO_SERVER_BURDEN_LOGICS_DEMO7_REQ_HANDLER_H_

#include "msg_handler.h"

namespace burden
{
class Demo7ReqHandler : public MsgHandler
{
public:
    Demo7ReqHandler();
    virtual ~Demo7ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_BURDEN_LOGICS_DEMO7_REQ_HANDLER_H_
