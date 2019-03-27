#ifndef DEMO_SERVER_GLOBAL_SOME_MODULE_H_
#define DEMO_SERVER_GLOBAL_SOME_MODULE_H_

#include "the_global_logic_interface.h"
#include "thread_lock.h"

namespace global
{
class SomeModule : public SomeModuleInterface
{
public:
    SomeModule();
    virtual ~SomeModule();

    int Initialize(const void* ctx);
    void Finalize();
    int Activate();
    void Freeze();

    ///////////////////////// global::SomeModuleInterface /////////////////////////
    int Func(const char* arg) override;

private:
    LogicCtx* logic_ctx_;
    ThreadMutex mutex_;

};
}

#endif // DEMO_SERVER_GLOBAL_SOME_MODULE_H_
