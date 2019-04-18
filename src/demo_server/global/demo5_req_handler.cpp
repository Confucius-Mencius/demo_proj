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

void Demo5ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo5ReqHandler::OnMsg");

    ss::Demo5Req demo5_req;
    if (ParseProtobufMsg(&demo5_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo5_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo50_req_msg_head = { 0, ss::MSG_ID_DEMO50_REQ };

    ss::Demo50Req demo50_req;
    demo50_req.set_a(50);

    if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo50_req_msg_head, &demo50_req,
                         demo5_req.work_thread_idx()) != 0)
    {
        LOG_ERROR("failed to send to work thread, msg id: " << demo50_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo5_nfy_msg_head = { NFY_PASSBACK, ss::MSG_ID_DEMO5_NFY };

    ss::Demo5Nfy demo5_nfy;
    demo5_nfy.set_a(5);

    if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo5_nfy_msg_head, &demo5_nfy, -1) != 0) // 广播
    {
        LOG_ERROR("failed to broadcast to work threads, msg id: " << demo5_nfy_msg_head.msg_id);
        return;
    }
}
}
