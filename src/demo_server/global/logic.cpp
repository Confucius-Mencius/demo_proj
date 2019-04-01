#include "logic.h"

namespace global
{
Logic::Logic() : conf_mgr_(), msg_handler_mgr_(), some_module_(), common_timers_()
{
}

Logic::~Logic()
{
}

const char* Logic::GetVersion() const
{
    return NULL;
}

const char* Logic::GetLastErrMsg() const
{
    return NULL;
}

void Logic::Release()
{
    delete this;
}

int Logic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    if (conf_mgr_.Initialize(logic_ctx_.conf_center) != 0)
    {
        return -1;
    }

    if (msg_handler_mgr_.Initialize(&logic_ctx_) != 0)
    {
        return -1;
    }

    if (some_module_.Initialize(&logic_ctx_) != 0)
    {
        return -1;
    }

    if (common_timers_.Initialize(&logic_ctx_) != 0)
    {
        return -1;
    }

    return 0;
}

void Logic::Finalize()
{
    common_timers_.Finalize();
    some_module_.Finalize();
    msg_handler_mgr_.Finalize();
    conf_mgr_.Finalize();
}

int Logic::Activate()
{
    msg_handler_mgr_.SetGlobalLogic(static_cast<TheLogicInterface*>(this));

    if (msg_handler_mgr_.Activate() != 0)
    {
        return -1;
    }

    if (some_module_.Activate() != 0)
    {
        return -1;
    }

    if (common_timers_.Activate() != 0)
    {
        return -1;
    }

    return 0;
}

void Logic::Freeze()
{
    msg_handler_mgr_.Freeze();
    common_timers_.Freeze();
    some_module_.Freeze();
}

void Logic::OnStop()
{
    can_exit_ = true;
}

void Logic::OnReload()
{
    conf_mgr_.Reload();
}

ConfMgrInterface* Logic::GetConfMgr() const
{
    return (ConfMgrInterface*) &conf_mgr_;
}

SomeModuleInterface* Logic::GetSomeModule() const
{
    return const_cast<SomeModule*>(&some_module_);
}
}
