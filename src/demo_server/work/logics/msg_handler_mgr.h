#ifndef DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_MGR_H_

#include "proto_msg_handler_mgr_template.h"
#include "demo5_nfy_handler.h"
#include "demo4_req_handler.h"
#include "demo6_req_handler.h"
#include "demo50_req_handler.h"
#include "demo200_req_handler.h"
#include "demo1005_nfy_handler.h"
#include "demo1004_req_handler.h"
#include "demo1006_req_handler.h"
#include "demo1050_req_handler.h"
#include "demo300_req_handler.h"
#include "demo301_nfy_handler.h"

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
    Demo5NfyHandler demo5_nfy_handler_;
    Demo4ReqHandler demo4_req_handler_;
    Demo6ReqHandler demo6_req_handler_;
    Demo50ReqHandler demo50_req_handler_;
    Demo200ReqHandler demo200_req_handler_;
    Demo1005NfyHandler demo1005_nfy_handler_;
    Demo1004ReqHandler demo1004_req_handler_;
    Demo1006ReqHandler demo1006_req_handler_;
    Demo1050ReqHandler demo1050_req_handler_;
    Demo300ReqHandler demo300_req_handler_;
    Demo301NfyHandler demo301_nfy_handler_;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_MGR_H_
