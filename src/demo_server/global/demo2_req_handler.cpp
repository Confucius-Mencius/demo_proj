#include "demo2_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo2ReqHandler::Demo2ReqHandler()
{
}

Demo2ReqHandler::~Demo2ReqHandler()
{
}

::proto::MsgID Demo2ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO2_REQ;
}

void Demo2ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo2ReqHandler::OnMsg");

    ss::Demo2Req demo2_req;
    if (ParseProtobufMsg(&demo2_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo2_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo20_req_msg_head = { 0, ss::MSG_ID_DEMO20_REQ };

    ss::Demo20Req demo20_req;
    demo20_req.set_a(20);

    if (SendToProtoTCPThread(logic_ctx_->scheduler, conn_guid, demo20_req_msg_head, &demo20_req,
                             demo2_req.proto_tcp_thread_idx()) != 0)
    {
        LOG_ERROR("failed to send to proto tcp thread, msg id: " << demo20_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo2_nfy_msg_head = { NFY_PASSBACK, ss::MSG_ID_DEMO2_NFY };

    ss::Demo2Nfy demo2_nfy;
    demo2_nfy.set_a(2);

    if (SendToProtoTCPThread(logic_ctx_->scheduler, conn_guid, demo2_nfy_msg_head, &demo2_nfy, -1) != 0) // 广播
    {
        LOG_ERROR("failed to broadcast to proto tcp threads, msg id: " << demo2_nfy_msg_head.msg_id);
        return;
    }
}
}
