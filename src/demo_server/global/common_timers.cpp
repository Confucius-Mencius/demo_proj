#include "common_timers.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
enum
{
    DEMO_TIMER_ID = 1,
};

CommonTimers::CommonTimers()
{
    logic_ctx_ = nullptr;
}

CommonTimers::~CommonTimers()
{
}

int CommonTimers::Initialize(const void* ctx)
{
    logic_ctx_ = (LogicCtx*) ctx;
    return 0;
}

void CommonTimers::Finalize()
{
}

int CommonTimers::Activate()
{
    struct timeval tv = { 60, 0 };

    if (logic_ctx_->timer_axis->SetTimer(this, DEMO_TIMER_ID, tv, NULL, 0) != 0)
    {
        LOG_ERROR("failed to add timer");
        return -1;
    }

    return 0;
}

void CommonTimers::Freeze()
{
    logic_ctx_->timer_axis->KillTimer(this, DEMO_TIMER_ID);
}

void CommonTimers::OnTimer(TimerID timer_id, void* data, size_t len, int times)
{
    LOG_TRACE("in common timers");

    ::proto::MsgHead msg_head;
    msg_head.msg_id = ss::MSG_ID_GLOBAL_REQ;

    ss::GlobalReq global_req;
    global_req.set_a(1);
    global_req.set_b(2);

    SendToWorkThread(logic_ctx_->scheduler, nullptr, msg_head, &global_req, -1);
}
}
