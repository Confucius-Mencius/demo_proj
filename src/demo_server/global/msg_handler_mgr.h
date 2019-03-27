#ifndef DEMO_SERVER_GLOBAL_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_GLOBAL_MSG_HANDLER_MGR_H_

#include "demo_6_req_handler.h"
#include "proto_msg_handler_mgr_template.h"

namespace global
{
class MsgHandlerMgr : public ::proto::MsgHandlerMgrTemplate<MsgHandler>
{
public:
    MsgHandlerMgr();
    virtual ~MsgHandlerMgr();

    ///////////////////////// MsgHandlerMgrInterface /////////////////////////
    int Initialize(const void* ctx) override;

public:
    void SetGlobalLogic(TheLogicInterface* global_logic);

private:
    ///////////////////////// MsgHandlerMgrTemplate /////////////////////////
    int InitializeMsgHandlerVec() override;
    void FinalizeMsgHandlerVec() override;

private:
    Demo6ReqHandler demo_6_req_handler_;
};
}

#endif // DEMO_SERVER_GLOBAL_MSG_HANDLER_MGR_H_
