#include "demo1005_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo1005ReqHandler::Demo1005ReqHandler()
{
}

Demo1005ReqHandler::~Demo1005ReqHandler()
{
}

::proto::MsgID Demo1005ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1005_REQ;
}

void Demo1005ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo1005ReqHandler::OnMsg");

    ss::Demo1005Req demo1005_req;
    if (ParseProtobufMsg(&demo1005_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo1005_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1050_req_msg_head = { 0, ss::MSG_ID_DEMO1050_REQ };

    ss::Demo1050Req demo1050_req;
    demo1050_req.set_a(50);

    if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo1050_req_msg_head, &demo1050_req,
                         demo1005_req.work_thread_idx()) != 0)
    {
        LOG_ERROR("failed to send to work thread, msg id: " << demo1050_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1005_nfy_msg_head = { NFY_PASSBACK, ss::MSG_ID_DEMO1005_NFY };

    ss::Demo1005Nfy demo1005_nfy;
    demo1005_nfy.set_a(1005);

    if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo1005_nfy_msg_head, &demo1005_nfy, -1) != 0) // 广播
    {
        LOG_ERROR("failed to broadcast to work threads, msg id: " << demo1005_nfy_msg_head.msg_id);
        return;
    }
}
}
