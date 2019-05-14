#include "msg_handler.h"

namespace tcp
{
namespace web
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

    common_logic_ = const_cast<TheCommonLogicInterface*>(static_cast<TheCommonLogicInterface*>(logic_ctx_->common_logic));
    return 0;
}
}
}
}
