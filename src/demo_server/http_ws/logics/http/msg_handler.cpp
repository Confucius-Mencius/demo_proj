#include "msg_handler.h"

namespace tcp
{
namespace http
{
MsgHandler::MsgHandler()
{
    global_logic_ = nullptr;
    common_logic_ = nullptr;
    logic_ = nullptr;
}

MsgHandler::~MsgHandler()
{
}

int MsgHandler::Initialize(const void* ctx)
{
    if (MsgHandlerInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    common_logic_ = const_cast<tcp::http_ws::TheCommonLogicInterface*>(static_cast<tcp::http_ws::TheCommonLogicInterface*>(logic_ctx_->common_logic));
    return 0;
}
}
}
