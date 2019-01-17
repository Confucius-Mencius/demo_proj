#include "echo_req_handler.h"
#include "log_util.h"
#include "tcp_logic_interface.h"

namespace tcp
{
EchoReqHandler::EchoReqHandler()
{

}

EchoReqHandler::~EchoReqHandler()
{

}

MsgId EchoReqHandler::GetMsgId()
{
    return 1000;
}

void EchoReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                           size_t msg_body_len)
{

    LOG_TRACE("tcp::EchoReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);
    logic_ctx_->scheduler->SendToClient(conn_guid, msg_head, msg_body, msg_body_len);
}
}
