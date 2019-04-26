#ifndef DEMO_SERVER_PROTO_TCP_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_PROTO_TCP_LOGICS_MSG_HANDLER_MGR_H_

#include "proto_msg_handler_mgr_template.h"
#include "demo100_req_handler.h"
#include "demo1_req_handler.h"
#include "demo2_nfy_handler.h"
#include "demo3_req_handler.h"
#include "demo8_req_handler.h"
#include "demo20_req_handler.h"
#include "demo301_req_handler.h"
#include "demo302_req_handler.h"

namespace tcp
{
namespace proto
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
    Demo100ReqHandler demo100_req_handler_;
    Demo1ReqHandler demo1_req_handler_;
    Demo2NfyHandler demo2_nfy_handler_;
    Demo3ReqHandler demo3_req_handler_;
    Demo8ReqHandler demo8_req_handler_;
    Demo20ReqHandler demo20_req_handler_;
    Demo301ReqHandler demo301_req_handler_;
    Demo302ReqHandler demo302_req_handler_;
};
}
}

#endif // DEMO_SERVER_PROTO_TCP_LOGICS_MSG_HANDLER_MGR_H_
