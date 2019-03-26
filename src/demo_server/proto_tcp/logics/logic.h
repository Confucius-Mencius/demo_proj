#ifndef DEMO_SERVER_PROTO_TCP_LOGICS_LOGIC_H_
#define DEMO_SERVER_PROTO_TCP_LOGICS_LOGIC_H_

#include "proto_tcp_logic_interface.h"

namespace tcp
{
namespace proto
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
};
}
}

#endif // DEMO_SERVER_PROTO_TCP_LOGICS_LOGIC_H_
