#include "demo_6_req_handler.h"
#include "burden_protobuf_msg_util.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "log_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo6ReqHandler::Demo6ReqHandler()
{

}

Demo6ReqHandler::~Demo6ReqHandler()
{

}

MsgId Demo6ReqHandler::GetMsgId()
{
    return proto::cs::MSG_ID_DEMO_6_REQ;
}

void Demo6ReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                            size_t msg_body_len)
{
    LOG_TRACE(
        "burden::Demo6ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo6Req demo_6_req;
    if (ParseProtobufMsg(&demo_6_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    if (SendToGlobalThread(logic_ctx_->scheduler, conn_guid, msg_head, &demo_6_req) != 0)
    {
        LOG_ERROR("failed to send to global thread");
        return;
    }
}
}
