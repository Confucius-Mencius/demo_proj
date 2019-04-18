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

void Demo9ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo9ReqHandler::OnMsg");

    ss::Demo9Req demo9_req;
    if (ParseProtobufMsg(&demo9_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo9_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo90_req_msg_head = { 0, ss::MSG_ID_DEMO90_REQ };

    ss::Demo90Req demo90_req;
    demo90_req.set_a(90);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo90_req_msg_head, &demo90_req,
                           demo9_req.burden_thread_idx()) != 0)
    {
        LOG_ERROR("failed to send to burden thread, msg id: " << demo90_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo9_nfy_msg_head = { NFY_PASSBACK, ss::MSG_ID_DEMO9_NFY };

    ss::Demo9Nfy demo9_nfy;
    demo9_nfy.set_a(9);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo9_nfy_msg_head, &demo9_nfy, -1) != 0) // 广播
    {
        LOG_ERROR("failed to broadcast to burden threads, msg id: " << demo9_nfy_msg_head.msg_id);
        return;
    }
}
}
