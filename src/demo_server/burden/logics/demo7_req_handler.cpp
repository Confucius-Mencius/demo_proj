#include "demo7_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo7ReqHandler::Demo7ReqHandler()
{
}

Demo7ReqHandler::~Demo7ReqHandler()
{
}

::proto::MsgID Demo7ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO7_REQ;
}

void Demo7ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo7ReqHandler::OnMsg");

    ss::Demo7Req demo7_req;
    if (ParseProtobufMsg(&demo7_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
