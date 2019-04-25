#include "common_logic.h"
#include "log_util.h"
#include "tcp_scheduler_interface.h"

namespace tcp
{
CommonLogic::CommonLogic()
{
}

CommonLogic::~CommonLogic()
{
}

const char* CommonLogic::GetVersion() const
{
    return nullptr;
}

const char* CommonLogic::GetLastErrMsg() const
{
    return nullptr;
}

void CommonLogic::Release()
{
    delete this;
}

int CommonLogic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    return 0;
}

void CommonLogic::Finalize()
{
}

int CommonLogic::Activate()
{
    return 0;
}

void CommonLogic::Freeze()
{
}

void CommonLogic::OnStop()
{
    can_exit_ = true;
}

void CommonLogic::OnReload()
{
}

void CommonLogic::OnClientConnected(const ConnGUID* conn_guid)
{
}

void CommonLogic::OnClientClosed(const ConnGUID* conn_guid)
{
}

void CommonLogic::OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len)
{
}

void CommonLogic::OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len)
{
}
}
