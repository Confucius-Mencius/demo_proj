#ifndef DEMO_SERVER_TCP_COMMON_LOGIC_COMMON_LOGIC_H_
#define DEMO_SERVER_TCP_COMMON_LOGIC_COMMON_LOGIC_H_

#include "tcp_common_logic_interface.h"

namespace tcp
{
class CommonLogic : public TheCommonLogicInterface
{
public:
    CommonLogic();
    virtual ~CommonLogic();

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

#if defined(USE_BUFFEREVENT)
    void OnRecvClientData(const ConnGUID* conn_guid, const void* data, size_t len) override;
#else
    /**
     *
     * @param closed 如果read返回0，表示对端关闭了，需要将closed置为true。如果read返回-1，且errno为ECONNRESET，也要将closed置为true
     * @param conn_guid
     * @param sock_fd
     * @attention 需要循环读到出错为止
     */
    void OnRecvClientData(bool& closed, const ConnGUID* conn_guid, int sock_fd) override;
#endif

    void OnTask(const ConnGUID* conn_guid, ThreadInterface* source_thread, const void* data, size_t len) override;

    ///////////////////////// TheCommonLogicInterface /////////////////////////

};
}

#endif // DEMO_SERVER_TCP_COMMON_LOGIC_COMMON_LOGIC_H_
