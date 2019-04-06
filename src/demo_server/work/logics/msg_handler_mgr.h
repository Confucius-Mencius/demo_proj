#ifndef DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_MGR_H_

#include "proto_msg_handler_mgr_template.h"
#include "demo5_nfy_handler.h"
#include "demo4_req_handler.h"
#include "demo6_req_handler.h"
#include "demo50_req_handler.h"
#include "demo200_req_handler.h"

namespace work
{
class Logic;

class MsgHandlerMgr : public ::proto::MsgHandlerMgrTemplate<MsgHandler>
{
public:
    MsgHandlerMgr();
    virtual ~MsgHandlerMgr();

    ///////////////////////// MsgHandlerMgrInterface /////////////////////////
    int Initialize(const void* ctx) override;

public:
    void SetGlobalLogic(global::TheLogicInterface* global_logic);
    void SetLogic(Logic* logic);

private:
    ///////////////////////// MsgHandlerMgrTemplate /////////////////////////
    int InitializeMsgHandlerVec() override;
    void FinalizeMsgHandlerVec() override;

private:
    Demo5NfyHandler demo4_nfy_handler_;
    Demo4ReqHandler demo4_req_handler_;
    Demo6ReqHandler demo6_req_handler_;
    Demo50ReqHandler demo50_req_handler_;
    Demo200ReqHandler demo200_req_handler_;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_MGR_H_
