#ifndef DEMO_SERVER_RAW_TCP_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_RAW_TCP_LOGICS_MSG_HANDLER_MGR_H_

#include "proto_msg_handler_mgr_template.h"
#include "demo1002_nfy_handler.h"
#include "demo1003_req_handler.h"
#include "demo1008_req_handler.h"
#include "demo1020_req_handler.h"

namespace tcp
{
namespace raw
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
    Demo1002NfyHandler demo1002_nfy_handler_;
    Demo1003ReqHandler demo1003_req_handler_;
    Demo1008ReqHandler demo1008_req_handler_;
    Demo1020ReqHandler demo1020_req_handler_;
};
}
}

#endif // DEMO_SERVER_RAW_TCP_LOGICS_MSG_HANDLER_MGR_H_
