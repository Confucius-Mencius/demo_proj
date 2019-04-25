#include "demo1002_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo1002ReqHandler::Demo1002ReqHandler()
{
}

Demo1002ReqHandler::~Demo1002ReqHandler()
{
}

::proto::MsgID Demo1002ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1002_REQ;
}

void Demo1002ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo1002ReqHandler::OnMsg");

    ss::Demo1002Req demo1002_req;
    if (ParseProtobufMsg(&demo1002_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1002_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1020_req_msg_head = { 0, ss::MSG_ID_DEMO1020_REQ };

    ss::Demo1020Req demo1020_req;
    demo1020_req.set_a(20);

    if (SendToTCPThread(logic_ctx_->scheduler, conn_guid, demo1020_req_msg_head, &demo1020_req,
                        demo1002_req.tcp_thread_idx()) != 0)
    {
        LOG_ERROR("failed to send to tcp thread, msg id: " << demo1020_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1002_nfy_msg_head = { NFY_PASSBACK, ss::MSG_ID_DEMO1002_NFY };

    ss::Demo1002Nfy demo1002_nfy;
    demo1002_nfy.set_a(1002);

    if (SendToTCPThread(logic_ctx_->scheduler, conn_guid, demo1002_nfy_msg_head, &demo1002_nfy, -1) != 0) // 广播
    {
        LOG_ERROR("failed to broadcast to tcp threads, msg id: " << demo1002_nfy_msg_head.msg_id);
        return;
    }
}
}
