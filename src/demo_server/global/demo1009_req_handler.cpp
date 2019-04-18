#include "demo1009_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "global_protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo1009ReqHandler::Demo1009ReqHandler()
{
}

Demo1009ReqHandler::~Demo1009ReqHandler()
{
}

::proto::MsgID Demo1009ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1009_REQ;
}

void Demo1009ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo1009ReqHandler::OnMsg");

    ss::Demo1009Req demo1009_req;
    if (ParseProtobufMsg(&demo1009_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1009_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1090_req_msg_head = { 0, ss::MSG_ID_DEMO1090_REQ };

    ss::Demo1090Req demo1090_req;
    demo1090_req.set_a(1090);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo1090_req_msg_head, &demo1090_req,
                           demo1009_req.burden_thread_idx()) != 0)
    {
        LOG_ERROR("failed to send to burden thread, msg id: " << demo1090_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1009_nfy_msg_head = { NFY_PASSBACK, ss::MSG_ID_DEMO1009_NFY };

    ss::Demo1009Nfy demo1009_nfy;
    demo1009_nfy.set_a(1009);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo1009_nfy_msg_head, &demo1009_nfy, -1) != 0) // 广播
    {
        LOG_ERROR("failed to broadcast to burden threads, msg id: " << demo1009_nfy_msg_head.msg_id);
        return;
    }
}
}
