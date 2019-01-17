#include "msg_handler_mgr.h"
#include "udp_logic_interface.h"

namespace udp
{
MsgHandlerMgr::MsgHandlerMgr()
{
}

MsgHandlerMgr::~MsgHandlerMgr()
{
}

int MsgHandlerMgr::Initialize(const void* ctx)
{
    if (NULL == ctx)
    {
        return -1;
    }

    LogicCtx* logic_ctx = (LogicCtx*) ctx;
    msg_dispatcher_ = logic_ctx->msg_dispatcher;

    if (base::MsgHandlerMgrTemplate<MsgHandler>::Initialize(ctx) != 0)
    {
        return -1;
    }

//    for (MsgHandlerVec::iterator it = msg_handler_vec_.begin(); it != msg_handler_vec_.end(); ++it)
//    {
//    }

    return 0;
}

void MsgHandlerMgr::SetLogic(Logic* logic)
{
    for (MsgHandlerVec::iterator it = msg_handler_vec_.begin(); it != msg_handler_vec_.end(); ++it)
    {
        (*it)->SetLogic(logic);
    }
}

int MsgHandlerMgr::InitializeMsgHandlerVec()
{
    msg_handler_vec_.push_back(&echo_req_handler_);

    return 0;
}

void MsgHandlerMgr::FinalizeMsgHandlerVec()
{
    msg_handler_vec_.clear();
}
}
