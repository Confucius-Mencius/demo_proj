#include "demo20_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo20ReqHandler::Demo20ReqHandler()
{
}

Demo20ReqHandler::~Demo20ReqHandler()
{
}

::proto::MsgID Demo20ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO20_REQ;
}

void Demo20ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                             const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo20ReqHandler::OnMsg");

    ss::Demo20Req demo20_req;
    if (ParseProtobufMsg(&demo20_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo20_req.a());
}
}
}
