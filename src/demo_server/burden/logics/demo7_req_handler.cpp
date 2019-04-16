#include "demo7_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo7ReqHandler::Demo7ReqHandler()
{
}

Demo7ReqHandler::~Demo7ReqHandler()
{
}

::proto::MsgID Demo7ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO7_REQ;
}

void Demo7ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo7ReqHandler::OnMsg");

    ss::Demo7Req demo7_req;
    if (ParseProtobufMsg(&demo7_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo7_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo9_req_msg_head = { 0, ss::MSG_ID_DEMO9_REQ };

    ss::Demo9Req demo9_req;
    demo9_req.set_a(9);
    demo9_req.set_burden_thread_idx(logic_ctx_->thread_idx);

    if (SendToGlobalThread(logic_ctx_->scheduler, conn_guid, demo9_req_msg_head, &demo9_req) != 0)
    {
        LOG_ERROR("failed to send to global thread, " << *conn_guid << ", msg id: " << demo9_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo10_req_msg_head = { 0, ss::MSG_ID_DEMO10_REQ };

    ss::Demo10Req demo10_req;
    demo10_req.set_a(10);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo10_req_msg_head, &demo10_req, -1) != 0)
    {
        LOG_ERROR("failed to send to global thread, " << *conn_guid << ", msg id: " << demo10_req_msg_head.msg_id);
        return;
    }
}
}
