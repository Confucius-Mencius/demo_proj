#include "msg_handler.h"

namespace work
{
MsgHandler::MsgHandler()
{
    global_logic_ = nullptr;
    local_logic_ = nullptr;
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

    local_logic_ = (TheLocalLogicInterface*) logic_ctx_->local_logic;
    return 0;
}
}
