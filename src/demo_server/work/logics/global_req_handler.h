#ifndef DEMO_SERVER_WORK_LOGICS_GLOBAL_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_GLOBAL_REQ_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class GlobalReqHandler : public MsgHandler
{
public:
    GlobalReqHandler();
    virtual ~GlobalReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    MsgId GetMsgId() override;
    void OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
               size_t msg_body_len) override;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_GLOBAL_REQ_HANDLER_H_
