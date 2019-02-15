#include "common_logic.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "log_util.h"
#include "ws_scheduler_interface.h"

namespace ws
{
CommonLogic::CommonLogic()
{
}

CommonLogic::~CommonLogic()
{
}

const char* CommonLogic::GetVersion() const
{
    return NULL;
}

const char* CommonLogic::GetLastErrMsg() const
{
    return NULL;
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
    LOG_TRACE("conn connected, " << *conn_guid);
}

void CommonLogic::OnClientClosed(const ConnGUID* conn_guid)
{
    LOG_TRACE("conn closed, " << *conn_guid);
}

void CommonLogic::OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len)
{
    // echo, for test only
    logic_ctx_.scheduler->SendToClient(conn_guid, data, len);
}

void CommonLogic::OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len)
{
    (void) conn_guid;
    (void) source_thread;
    (void) data;
    (void) len;
}
}
