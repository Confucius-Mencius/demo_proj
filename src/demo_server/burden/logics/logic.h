#ifndef DEMO_SERVER_BURDEN_LOGICS_LOGIC_H_
#define DEMO_SERVER_BURDEN_LOGICS_LOGIC_H_

#include "burden_logic_interface.h"
#include "msg_handler_mgr.h"

namespace burden
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

    ///////////////////////// burden::LogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;

private:
    MsgHandlerMgr msg_handler_mgr_;
};
}

#endif // DEMO_SERVER_BURDEN_LOGICS_LOGIC_H_
