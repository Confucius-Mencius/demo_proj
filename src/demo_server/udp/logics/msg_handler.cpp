#include "msg_handler.h"

namespace udp
{
MsgHandler::MsgHandler()
{
    logic_ = NULL;
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

    return 0;
}
}
