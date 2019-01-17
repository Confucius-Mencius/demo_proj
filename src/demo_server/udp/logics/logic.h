#ifndef DEMO_SERVER_UDP_LOGICS_LOGIC_H_
#define DEMO_SERVER_UDP_LOGICS_LOGIC_H_

#include "msg_handler_mgr.h"
#include "udp_logic_interface.h"

namespace udp
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

    ///////////////////////// udp::LogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;

private:
    MsgHandlerMgr msg_handler_mgr_;
};
}

#endif // DEMO_SERVER_UDP_LOGICS_LOGIC_H_
