#include "demo90_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo90ReqHandler::Demo90ReqHandler()
{
}

Demo90ReqHandler::~Demo90ReqHandler()
{
}

::proto::MsgID Demo90ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO90_REQ;
}

void Demo90ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                             const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo90ReqHandler::OnMsg");

    ss::Demo90Req demo90_req;
    if (ParseProtobufMsg(&demo90_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo90_req.a());
}
}
