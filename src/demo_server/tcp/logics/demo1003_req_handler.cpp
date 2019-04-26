#include "demo1003_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
Demo1003ReqHandler::Demo1003ReqHandler()
{
}

Demo1003ReqHandler::~Demo1003ReqHandler()
{
}

::proto::MsgID Demo1003ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1003_REQ;
}

void Demo1003ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::Demo1003ReqHandler::OnMsg");

    ss::Demo1003Req demo1003_req;
    if (ParseProtobufMsg(&demo1003_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo1003_req.a());
}
}
