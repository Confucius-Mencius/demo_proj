#include "demo1010_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo1010ReqHandler::Demo1010ReqHandler()
{
}

Demo1010ReqHandler::~Demo1010ReqHandler()
{
}

::proto::MsgID Demo1010ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1010_REQ;
}

void Demo1010ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo1010ReqHandler::OnMsg");

    ss::Demo1010Req demo1010_req;
    if (ParseProtobufMsg(&demo1010_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo1010_req.a());
}
}
