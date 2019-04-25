#include "demo1008_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
Demo1008ReqHandler::Demo1008ReqHandler()
{
}

Demo1008ReqHandler::~Demo1008ReqHandler()
{
}

::proto::MsgID Demo1008ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1008_REQ;
}

void Demo1008ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::Demo1008ReqHandler::OnMsg");

    ss::Demo1008Req demo1008_req;
    if (ParseProtobufMsg(&demo1008_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1008_req.a());
}
}
