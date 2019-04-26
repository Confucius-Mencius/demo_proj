#include "demo1006_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo1006ReqHandler::Demo1006ReqHandler()
{
}

Demo1006ReqHandler::~Demo1006ReqHandler()
{
}

::proto::MsgID Demo1006ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1006_REQ;
}

void Demo1006ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo1006ReqHandler::OnMsg");

    ss::Demo1006Req demo1006_req;
    if (ParseProtobufMsg(&demo1006_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo1006_req.a());
}
}
