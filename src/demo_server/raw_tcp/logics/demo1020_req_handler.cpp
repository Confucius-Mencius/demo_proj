#include "demo1020_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace raw
{
Demo1020ReqHandler::Demo1020ReqHandler()
{
}

Demo1020ReqHandler::~Demo1020ReqHandler()
{
}

::proto::MsgID Demo1020ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1020_REQ;
}

void Demo1020ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::raw::Demo1020ReqHandler::OnMsg");

    ss::Demo1020Req demo1020_req;
    if (ParseProtobufMsg(&demo1020_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1020_req.a());
}
}
}
