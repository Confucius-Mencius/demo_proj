#include "demo1050_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo1050ReqHandler::Demo1050ReqHandler()
{
}

Demo1050ReqHandler::~Demo1050ReqHandler()
{
}

::proto::MsgID Demo1050ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1050_REQ;
}

void Demo1050ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo1050ReqHandler::OnMsg");

    ss::Demo1050Req demo1050_req;
    if (ParseProtobufMsg(&demo1050_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1050_req.a());
}
}
