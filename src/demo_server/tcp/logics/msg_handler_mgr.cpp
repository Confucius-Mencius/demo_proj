#include "msg_handler_mgr.h"

namespace tcp
{
MsgHandlerMgr::MsgHandlerMgr()
{
}

MsgHandlerMgr::~MsgHandlerMgr()
{
}

int MsgHandlerMgr::Initialize(const void* ctx)
{
    if (nullptr == ctx)
    {
        return -1;
    }

    LogicCtx* logic_ctx = (LogicCtx*) ctx;
    msg_dispatcher_ = logic_ctx->msg_dispatcher;

    if (::proto::MsgHandlerMgrTemplate<MsgHandler>::Initialize(ctx) != 0)
    {
        return -1;
    }

//    for (MsgHandlerVec::iterator it = msg_handler_vec_.begin(); it != msg_handler_vec_.end(); ++it)
//    {
//    }

    return 0;
}

void MsgHandlerMgr::SetGlobalLogic(global::TheLogicInterface* global_logic)
{
    for (MsgHandlerVec::iterator it = msg_handler_vec_.begin(); it != msg_handler_vec_.end(); ++it)
    {
        (*it)->SetGlobalLogic(global_logic);
    }
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
    msg_handler_vec_.push_back(&demo1002_nfy_handler_);
    msg_handler_vec_.push_back(&demo1003_req_handler_);
    msg_handler_vec_.push_back(&demo1008_req_handler_);
    msg_handler_vec_.push_back(&demo1020_req_handler_);

    return 0;
}

void MsgHandlerMgr::FinalizeMsgHandlerVec()
{
    msg_handler_vec_.clear();
}
}
