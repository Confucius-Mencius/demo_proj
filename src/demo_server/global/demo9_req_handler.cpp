#include "demo9_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo9ReqHandler::Demo9ReqHandler()
{
}

Demo9ReqHandler::~Demo9ReqHandler()
{
}

::proto::MsgID Demo9ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO9_REQ;
}

void Demo9ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo9ReqHandler::OnMsg");

    ss::Demo9Req demo9_req;
    if (ParseProtobufMsg(&demo9_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
