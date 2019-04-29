#ifndef DEMO_SERVER_HTTP_WS_LOGICS_HTTP_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_HTTP_WS_LOGICS_HTTP_MSG_HANDLER_MGR_H_

#include "http_msg_handler_mgr_template.h"
#include "crossdomain_req_handler.h"
#include "demo_req_handler.h"
#include "demo1_req_handler.h"
#include "demo2_req_handler.h"

namespace tcp
{
namespace http_ws
{
class Logic;

namespace http
{
class MsgHandlerMgr : public MsgHandlerMgrTemplate<MsgHandler>
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
    CrossdomainReqHandler crossdomain_req_handler_;
    DemoReqHandler demo_req_handler_;
    Demo1ReqHandler demo1_req_handler_;
    Demo2ReqHandler demo2_req_handler_;
};
}
}
}

#endif // DEMO_SERVER_HTTP_WS_LOGICS_HTTP_MSG_HANDLER_MGR_H_
