#ifndef DEMO_SERVER_GLOBAL_COMMON_TIMERS_H_
#define DEMO_SERVER_GLOBAL_COMMON_TIMERS_H_

// 公共定时器示例

#include "global_logic_interface.h"
#include "timer_axis_interface.h"

namespace global
{
class CommonTimers : public TimerSinkInterface
{
public:
    CommonTimers();
    virtual ~CommonTimers();

    int Initialize(const void* ctx);
    void Finalize();
    int Activate();
    void Freeze();

    ///////////////////////// TimerSinkInterface /////////////////////////
    void OnTimer(TimerID timer_id, void* data, size_t len, int times) override;

private:
    LogicCtx* logic_ctx_;
};
}

#endif // DEMO_SERVER_GLOBAL_COMMON_TIMERS_H_
