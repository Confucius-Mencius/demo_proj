#ifndef DEMO_SERVER_WORK_LOGICS_DEMO1006_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO1006_REQ_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class Demo1006ReqHandler : public MsgHandler
{
public:
    Demo1006ReqHandler();
    virtual ~Demo1006ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO1006_REQ_HANDLER_H_
