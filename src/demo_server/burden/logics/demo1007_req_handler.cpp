#include "demo1007_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo1007ReqHandler::Demo1007ReqHandler()
{
}

Demo1007ReqHandler::~Demo1007ReqHandler()
{
}

::proto::MsgID Demo1007ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1007_REQ;
}

void Demo1007ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo1007ReqHandler::OnMsg");

    ss::Demo1007Req demo1007_req;
    if (ParseProtobufMsg(&demo1007_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo1007_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1009_req_msg_head = { 0, ss::MSG_ID_DEMO1009_REQ };

    ss::Demo1009Req demo1009_req;
    demo1009_req.set_a(1009);
    demo1009_req.set_burden_thread_idx(logic_ctx_->thread_idx);

    if (SendToGlobalThread(logic_ctx_->scheduler, conn_guid, demo1009_req_msg_head, &demo1009_req) != 0)
    {
        LOG_ERROR("failed to send to global thread, " << *conn_guid << ", msg id: " << demo1009_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1010_req_msg_head = { 0, ss::MSG_ID_DEMO1010_REQ };

    ss::Demo1010Req demo1010_req;
    demo1010_req.set_a(1010);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo1010_req_msg_head, &demo1010_req, -1) != 0)
    {
        LOG_ERROR("failed to send to burden thread, " << *conn_guid << ", msg id: " << demo1010_req_msg_head.msg_id);
        return;
    }
}
}
