#ifndef DEMO_SERVER_TCP_LOGICS_LOGIC_H_
#define DEMO_SERVER_TCP_LOGICS_LOGIC_H_

#include "msg_handler_mgr.h"
#include "tcp_logic_interface.h"

namespace tcp
{
class Logic : public LogicInterface
{
public:
    Logic();
    virtual ~Logic();

    ///////////////////////// ModuleInterface /////////////////////////
    const char* GetVersion() const override;
    const char* GetLastErrMsg() const override;
    void Release() override;
    int Initialize(const void* ctx) override;
    void Finalize() override;
    int Activate() override;
    void Freeze() override;

    ///////////////////////// tcp::LogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;
    void OnClientConnected(const ConnGuid* conn_guid) override;
    void OnClientClosed(const ConnGuid* conn_guid) override;

#if defined(USE_BUFFEREVENT)
    void OnRecvClientRawData(const ConnGuid* conn_guid, const void* data, size_t data_len) override;
#else
    void OnClientRawData(bool& closed, const ConnGuid* conn_guid, int sock_fd) override;
#endif

private:
    MsgHandlerMgr msg_handler_mgr_;
};
}

#endif // DEMO_SERVER_TCP_LOGICS_LOGIC_H_
