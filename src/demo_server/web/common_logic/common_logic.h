#ifndef DEMO_SERVER_WEB_COMMON_LOGIC_COMMON_LOGIC_H_
#define DEMO_SERVER_WEB_COMMON_LOGIC_COMMON_LOGIC_H_

#include "web_common_logic_interface.h"

namespace tcp
{
namespace web
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

    ///////////////////////// TheCommonLogicInterface /////////////////////////

};
}
}

#endif // DEMO_SERVER_WEB_COMMON_LOGIC_COMMON_LOGIC_H_
