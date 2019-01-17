#ifndef DEMO_SERVER_TCP_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_TCP_LOGICS_MSG_HANDLER_MGR_H_

#include "echo_req_handler.h"
#include "msg_handler_mgr_template.h"

namespace tcp
{
class Logic;

class MsgHandlerMgr : public base::MsgHandlerMgrTemplate<MsgHandler>
{
public:
    MsgHandlerMgr();
    virtual ~MsgHandlerMgr();

    ///////////////////////// MsgHandlerMgrInterface /////////////////////////
    int Initialize(const void* ctx) override;

public:
    void SetLogic(Logic* logic);

private:
    ///////////////////////// MsgHandlerMgrTemplate /////////////////////////
    int InitializeMsgHandlerVec() override;
    void FinalizeMsgHandlerVec() override;

private:
    EchoReqHandler echo_req_handler_;
};
}

#endif // DEMO_SERVER_TCP_LOGICS_MSG_HANDLER_MGR_H_
