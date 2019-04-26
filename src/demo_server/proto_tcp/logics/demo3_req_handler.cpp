#include "demo3_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo3ReqHandler::Demo3ReqHandler()
{
}

Demo3ReqHandler::~Demo3ReqHandler()
{
}

::proto::MsgID Demo3ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO3_REQ;
}

void Demo3ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo3ReqHandler::OnMsg");

    ss::Demo3Req demo3_req;
    if (ParseProtobufMsg(&demo3_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo3_req.a());
}
}
}
