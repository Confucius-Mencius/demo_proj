#ifndef DEMO_SERVER_TCP_LOGICS_DEMO1020_REQ_HANDLER_H_
#define DEMO_SERVER_TCP_LOGICS_DEMO1020_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
class Demo1020ReqHandler : public MsgHandler
{
public:
    Demo1020ReqHandler();
    virtual ~Demo1020ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_TCP_LOGICS_DEMO1020_REQ_HANDLER_H_
