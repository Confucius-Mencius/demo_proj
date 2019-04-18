#include "demo50_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo50ReqHandler::Demo50ReqHandler()
{
}

Demo50ReqHandler::~Demo50ReqHandler()
{
}

::proto::MsgID Demo50ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO50_REQ;
}

void Demo50ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                             const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo50ReqHandler::OnMsg");

    ss::Demo50Req demo50_req;
    if (ParseProtobufMsg(&demo50_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo50_req.a());
}
}
