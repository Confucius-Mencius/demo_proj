#ifndef DEMO_SERVER_PROTO_TCP_COMMON_LOGIC_COMMON_LOGIC_H_
#define DEMO_SERVER_PROTO_TCP_COMMON_LOGIC_COMMON_LOGIC_H_

#include <set>
#include "proto_tcp_common_logic_interface.h"
#include "timer_axis_interface.h"

namespace tcp
{
namespace proto
{
class CommonLogic : public TheCommonLogicInterface, public TimerSinkInterface
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
    int StartSendNfyTimer(const ConnGUID* conn_guid) override;

    ///////////////////////// TimerSinkInterface /////////////////////////
    void OnTimer(TimerID timer_id, void* data, size_t len, int times) override;

private:
    typedef std::set<ConnGUID> ConnSet;
    ConnSet conn_set_;
};
}
}

#endif // DEMO_SERVER_PROTO_TCP_COMMON_LOGIC_COMMON_LOGIC_H_
