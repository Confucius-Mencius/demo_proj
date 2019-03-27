#include "some_module.h"

namespace global
{
SomeModule::SomeModule() : mutex_()
{
    logic_ctx_ = NULL;
}

SomeModule::~SomeModule()
{

}

int SomeModule::Initialize(const void* ctx)
{
    logic_ctx_ = (LogicCtx*) ctx;
    return 0;
}

void SomeModule::Finalize()
{
}

int SomeModule::Activate()
{
    return 0;
}

void SomeModule::Freeze()
{

}

int SomeModule::Func(const char* arg)
{
    (void) arg;

    AUTO_THREAD_MUTEX(mutex_);

    // ...

    return 0;
}
}
