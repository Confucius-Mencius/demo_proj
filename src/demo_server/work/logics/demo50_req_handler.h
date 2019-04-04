#ifndef DEMO_SERVER_WORK_LOGICS_DEMO50_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO50_REQ_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class Demo50ReqHandler : public MsgHandler
{
public:
    Demo50ReqHandler();
    virtual ~Demo50ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO50_REQ_HANDLER_H_
