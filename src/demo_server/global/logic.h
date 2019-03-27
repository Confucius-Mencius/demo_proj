#ifndef DEMO_SERVER_GLOBAL_LOGIC_H_
#define DEMO_SERVER_GLOBAL_LOGIC_H_

#include "common_timers.h"
#include "conf_mgr.h"
#include "msg_handler_mgr.h"
#include "some_module.h"
#include "the_global_logic_interface.h"

namespace global
{
class Logic : public TheLogicInterface
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

    ///////////////////////// GlobalLogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;

    ///////////////////////// global::TheLogicInterface /////////////////////////
    ConfMgrInterface* GetConfMgr() const override;
    SomeModuleInterface* GetSomeModule() const override;

private:
    ConfMgr conf_mgr_;
    MsgHandlerMgr msg_handler_mgr_;
    SomeModule some_module_;
    CommonTimers common_timers_;
};
}

#endif // DEMO_SERVER_GLOBAL_LOGIC_H_
