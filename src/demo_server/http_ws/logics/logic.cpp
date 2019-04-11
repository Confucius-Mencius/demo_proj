#include "logic.h"
#include "log_util.h"
#include "http_ws_scheduler_interface.h"

namespace tcp
{
namespace http_ws
{
Logic::Logic() : http_msg_handler_mgr_()
{
}

Logic::~Logic()
{
}

const char* Logic::GetVersion() const
{
    return nullptr;
}

const char* Logic::GetLastErrMsg() const
{
    return nullptr;
}

void Logic::Release()
{
    delete this;
}

int Logic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    if (http_msg_handler_mgr_.Initialize(&logic_ctx_) != 0)
    {
        return -1;
    }

    return 0;
}

void Logic::Finalize()
{
    http_msg_handler_mgr_.Finalize();
}

int Logic::Activate()
{
    http_msg_handler_mgr_.SetGlobalLogic((global::TheLogicInterface*) global_logic_);
    http_msg_handler_mgr_.SetLogic(this);

    if (http_msg_handler_mgr_.Activate() != 0)
    {
        return -1;
    }

    return 0;
}

void Logic::Freeze()
{
    http_msg_handler_mgr_.Freeze();
}

void Logic::OnStop()
{
    can_exit_ = true;
}

void Logic::OnReload()
{
}

void Logic::OnClientConnected(const ConnGUID* conn_guid)
{
}

void Logic::OnClientClosed(const ConnGUID* conn_guid)
{
}

void Logic::OnWSMsg(const ConnGUID* conn_guid, int frame_type, const void* data, size_t len)
{
}
}
}
