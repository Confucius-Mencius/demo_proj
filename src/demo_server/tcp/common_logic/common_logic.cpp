#include "common_logic.h"
#include <errno.h>
#include <string.h>
#include <unistd.h>
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
    LOG_TRACE("conn connected, " << conn_guid);
}

void CommonLogic::OnClientClosed(const ConnGUID* conn_guid)
{
    LOG_TRACE("conn closed, " << conn_guid);
}

#if defined(USE_BUFFEREVENT)
void CommonLogic::OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len)
{
    LOG_TRACE("recv client data, len: " << len << ", " << *conn_guid);

    // echo, for test only
    logic_ctx_.scheduler->SendToClient(conn_guid, data, len);
}
#else
void CommonLogic::OnRecvClientData(bool& closed, const ConnGUID* conn_guid, int sock_fd)
{
    LOG_TRACE("recv client data, socket fd: " << sock_fd << ", " << *conn_guid);

    char buf[16384] = "";
    int max_read_len = 16384;

    while (true)
    {
        ssize_t n = read(sock_fd, buf, max_read_len);
        if (0 == n)
        {
            LOG_TRACE("read 0, eof");
            closed = true;
            return;
        }
        else if (n < 0)
        {
            const int err = errno;

            if (EINTR == err)
            {
                // 被信号中断了，可以继续读
                continue;
            }
            else if (EAGAIN == err || EWOULDBLOCK == err)
            {
                // 没有数据可读了
                return;
            }
            else if (ECONNRESET == err)
            {
                LOG_ERROR("conn reset by peer");
                closed = true;
                return;
            }
            else
            {
                LOG_ERROR("read error, n: " << n << ", socket fd: " << sock_fd << ", errno: " << err
                          << ", err msg: " << strerror(err));
                return;
            }
        }

        LOG_DEBUG("read len: " << n);

        // echo, for test only
        logic_ctx_.scheduler->SendToClient(conn_guid, buf, n);
    }
}
#endif

void CommonLogic::OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len)
{
    (void) conn_guid;
    (void) source_thread;
    (void) data;
    (void) len;
}
}
