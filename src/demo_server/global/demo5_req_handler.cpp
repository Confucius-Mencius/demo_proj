#include "demo5_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo5ReqHandler::Demo5ReqHandler()
{
}

Demo5ReqHandler::~Demo5ReqHandler()
{
}

::proto::MsgID Demo5ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO5_REQ;
}

void Demo5ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo5ReqHandler::OnMsg");

    ss::Demo5Req demo5_req;
    if (ParseProtobufMsg(&demo5_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
