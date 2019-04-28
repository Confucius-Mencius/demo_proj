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

    ///////////////////////// LogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;
    void OnClientConnected(const ConnGUID* conn_guid) override;
    void OnClientClosed(const ConnGUID* conn_guid) override;

    ///////////////////////// TheCommonLogicInterface /////////////////////////

};
}

#endif // DEMO_SERVER_TCP_COMMON_LOGIC_COMMON_LOGIC_H_
