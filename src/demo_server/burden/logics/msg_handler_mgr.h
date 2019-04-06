#ifndef DEMO_SERVER_BURDEN_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_BURDEN_LOGICS_MSG_HANDLER_MGR_H_

#include "proto_msg_handler_mgr_template.h"
#include "demo9_nfy_handler.h"
#include "demo7_req_handler.h"
#include "demo10_req_handler.h"
#include "demo90_req_handler.h"

namespace burden
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
    Demo9NfyHandler demo5_nfy_handler_;
    Demo7ReqHandler demo7_req_handler_;
    Demo10ReqHandler demo10_req_handler_;
    Demo90ReqHandler demo90_req_handler_;
};
}

#endif // DEMO_SERVER_BURDEN_LOGICS_MSG_HANDLER_MGR_H_
