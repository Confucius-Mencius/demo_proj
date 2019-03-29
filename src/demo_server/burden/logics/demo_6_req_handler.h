#ifndef DEMO_SERVER_BURDEN_LOGICS_DEMO_6_REQ_HANDLER_H_
#define DEMO_SERVER_BURDEN_LOGICS_DEMO_6_REQ_HANDLER_H_

#include "msg_handler.h"

namespace burden
{
class Demo6ReqHandler : public MsgHandler
{
public:
    Demo6ReqHandler();
    virtual ~Demo6ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    MsgId GetMsgId() override;
    void OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
               size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_BURDEN_LOGICS_DEMO_6_REQ_HANDLER_H_
