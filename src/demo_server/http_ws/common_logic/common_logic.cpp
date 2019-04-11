#include "common_logic.h"
#include "http_ws_scheduler_interface.h"
#include "log_util.h"
#include "ws_frame_maker.h"

namespace tcp
{
namespace http_ws
{
CommonLogic::CommonLogic()
{
}

CommonLogic::~CommonLogic()
{
}

const char* CommonLogic::GetVersion() const
{
    return nullptr;
}

const char* CommonLogic::GetLastErrMsg() const
{
    return nullptr;
}

void CommonLogic::Release()
{
    delete this;
}

int CommonLogic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    return 0;
}

void CommonLogic::Finalize()
{
}

int CommonLogic::Activate()
{
    return 0;
}

void CommonLogic::Freeze()
{
}

void CommonLogic::OnStop()
{
    can_exit_ = true;
}

void CommonLogic::OnReload()
{
}

void CommonLogic::OnClientConnected(const ConnGUID* conn_guid)
{
}

void CommonLogic::OnClientClosed(const ConnGUID* conn_guid)
{
}

void CommonLogic::OnWSMsg(const ConnGUID* conn_guid, int frame_type, const void* data, size_t len)
{
    // echo
    LOG_DEBUG((char*) data << ", len: " << len);

    tcp::http_ws::ws::FrameMaker ws_frame_maker;
    const std::string ws_frame = ws_frame_maker.SetFin(true)
                                 .SetFrameType(frame_type)
                                 .MakeFrame(data, len);

    logic_ctx_.scheduler->SendToClient(conn_guid, ws_frame.data(), ws_frame.size());
}
}
}
