#ifndef DEMO_SERVER_GLOBAL_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_GLOBAL_MSG_HANDLER_MGR_H_

#include "proto_msg_handler_mgr_template.h"
#include "demo2_req_handler.h"
#include "demo5_req_handler.h"
#include "demo9_req_handler.h"
#include "demo1002_req_handler.h"
#include "demo1005_req_handler.h"
#include "demo1009_req_handler.h"

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
    Demo2ReqHandler demo2_req_handler_;
    Demo5ReqHandler demo5_req_handler_;
    Demo9ReqHandler demo9_req_handler_;
    Demo1002ReqHandler demo1002_req_handler_;
    Demo1005ReqHandler demo1005_req_handler_;
    Demo1009ReqHandler demo1009_req_handler_;
};
}

#endif // DEMO_SERVER_GLOBAL_MSG_HANDLER_MGR_H_
