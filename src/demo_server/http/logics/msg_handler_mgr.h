#ifndef DEMO_SERVER_HTTP_LOGICS_MSG_HANDLER_MGR_H_
#define DEMO_SERVER_HTTP_LOGICS_MSG_HANDLER_MGR_H_

#include "echo_req_handler.h"
#include "http_msg_handler_mgr_template.h"

namespace http
{
class Logic;

class MsgHandlerMgr : public MsgHandlerMgrTemplate<MsgHandler>
{
public:
    MsgHandlerMgr();
    virtual ~MsgHandlerMgr();

    ///////////////////////// http::MsgHandlerMgrInterface /////////////////////////
    int Initialize(const void* ctx) override;

public:
    void SetLogic(Logic* logic);

private:
    ///////////////////////// http::MsgHandlerMgrTemplate /////////////////////////
    int InitializeMsgHandlerVec() override;
    void FinalizeMsgHandlerVec() override;

private:
    EchoReqHandler echo_req_handler_;
};
}

#endif // DEMO_SERVER_HTTP_LOGICS_MSG_HANDLER_MGR_H_
