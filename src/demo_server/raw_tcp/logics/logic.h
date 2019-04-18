#ifndef DEMO_SERVER_RAW_TCP_LOGICS_LOGIC_H_
#define DEMO_SERVER_RAW_TCP_LOGICS_LOGIC_H_

#include "msg_handler_mgr.h"
#include "raw_tcp_logic_interface.h"

namespace tcp
{
namespace raw
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
    void OnClientConnected(const ConnGUID* conn_guid) override;
    void OnClientClosed(const ConnGUID* conn_guid) override;
    void OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len) override;
    void OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len) override;

private:
    MsgHandlerMgr msg_handler_mgr_;
};
}
}

#endif // DEMO_SERVER_RAW_TCP_LOGICS_LOGIC_H_
