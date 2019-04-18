#include "demo8_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo8ReqHandler::Demo8ReqHandler()
{
}

Demo8ReqHandler::~Demo8ReqHandler()
{
}

::proto::MsgID Demo8ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO8_REQ;
}

void Demo8ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo8ReqHandler::OnMsg");

    ss::Demo8Req demo8_req;
    if (ParseProtobufMsg(&demo8_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo8_req.a());
}
}
}
