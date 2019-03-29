#include "local_logic.h"

namespace work
{
LocalLogic::LocalLogic()
{
}

LocalLogic::~LocalLogic()
{
}

const char* LocalLogic::GetVersion() const
{
    return NULL;
}

const char* LocalLogic::GetLastErrMsg() const
{
    return NULL;
}

void LocalLogic::Release()
{
    delete this;
}

int LocalLogic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    return 0;
}

void LocalLogic::Finalize()
{
}

int LocalLogic::Activate()
{
    return 0;
}

void LocalLogic::Freeze()
{
}

void LocalLogic::OnStop()
{
    can_exit_ = true;
}
}
