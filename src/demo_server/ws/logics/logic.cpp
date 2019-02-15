#include "logic.h"
#include "log_util.h"
#include "ws_scheduler_interface.h"

namespace ws
{
Logic::Logic()
{
}

Logic::~Logic()
{
}

const char* Logic::GetVersion() const
{
    return NULL;
}

const char* Logic::GetLastErrMsg() const
{
    return NULL;
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

    return 0;
}

void Logic::Finalize()
{
}

int Logic::Activate()
{
    return 0;
}

void Logic::Freeze()
{
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
    (void) conn_guid;
}

void Logic::OnClientClosed(const ConnGUID* conn_guid)
{
    (void) conn_guid;
}

void Logic::OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len)
{
    (void) conn_guid;
    (void) data;
    (void) len;
}

void Logic::OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len)
{
    (void) conn_guid;
    (void) source_thread;
    (void) data;
    (void) len;
}
}
