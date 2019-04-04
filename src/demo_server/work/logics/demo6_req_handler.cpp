#include "demo6_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo6ReqHandler::Demo6ReqHandler()
{
}

Demo6ReqHandler::~Demo6ReqHandler()
{
}

::proto::MsgID Demo6ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO6_REQ;
}

void Demo6ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo6ReqHandler::OnMsg");

    ss::Demo6Req demo6_req;
    if (ParseProtobufMsg(&demo6_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
