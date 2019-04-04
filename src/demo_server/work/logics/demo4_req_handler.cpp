#include "demo4_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo4ReqHandler::Demo4ReqHandler()
{
}

Demo4ReqHandler::~Demo4ReqHandler()
{
}

::proto::MsgID Demo4ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO4_REQ;
}

void Demo4ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo4ReqHandler::OnMsg");

    ss::Demo4Req demo4_req;
    if (ParseProtobufMsg(&demo4_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
