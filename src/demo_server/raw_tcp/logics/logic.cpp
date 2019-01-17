#include "logic.h"
#include "log_util.h"
#include "tcp_scheduler_interface.h"

namespace raw_tcp
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
    if (tcp::LogicInterface::Initialize(ctx) != 0)
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

void Logic::OnClientConnected(const ConnGuid* conn_guid)
{
}

void Logic::OnClientClosed(const ConnGuid* conn_guid)
{
}

#if defined(USE_BUFFEREVENT)

void Logic::OnRecvClientRawData(const ConnGuid* conn_guid, const void* data, size_t data_len)
{
}

#else

void Logic::OnClientRawData(bool& closed, const ConnGuid* conn_guid, int sock_fd)
{
}
#endif
}
