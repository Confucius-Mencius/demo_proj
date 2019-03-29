#include "global_req_handler.h"
#include "log_util.h"
#include "ss_msg_id.pb.h"
#include "ss_msg.pb.h"
#include "burden_protobuf_msg_util.h"

using namespace com::moon::demo;

namespace burden
{
GlobalReqHandler::GlobalReqHandler()
{

}

GlobalReqHandler::~GlobalReqHandler()
{

}

MsgId GlobalReqHandler::GetMsgId()
{
    return proto::ss::MSG_ID_GLOBAL_REQ;
}

void GlobalReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body,
                             size_t msg_body_len)
{
    LOG_TRACE(
        "burden::GlobalReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::ss::GlobalReq global_req;
    if (ParseProtobufMsg(&global_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(global_req.a() << ", " << global_req.b());
}
}
