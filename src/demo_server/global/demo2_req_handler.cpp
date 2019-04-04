#include "demo2_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo2ReqHandler::Demo2ReqHandler()
{
}

Demo2ReqHandler::~Demo2ReqHandler()
{
}

::proto::MsgID Demo2ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO2_REQ;
}

void Demo2ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo2ReqHandler::OnMsg");

    ss::Demo2Req demo2_req;
    if (ParseProtobufMsg(&demo2_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
