#include "demo1004_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo1004ReqHandler::Demo1004ReqHandler()
{
}

Demo1004ReqHandler::~Demo1004ReqHandler()
{
}

::proto::MsgID Demo1004ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1004_REQ;
}

void Demo1004ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo1004ReqHandler::OnMsg");

    ss::Demo1004Req demo1004_req;
    if (ParseProtobufMsg(&demo1004_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1004_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1005_req_msg_head = { 0, ss::MSG_ID_DEMO1005_REQ };

    ss::Demo1005Req demo1005_req;
    demo1005_req.set_a(1005);
    demo1005_req.set_work_thread_idx(logic_ctx_->thread_idx);

    if (SendToGlobalThread(logic_ctx_->scheduler, conn_guid, demo1005_req_msg_head, &demo1005_req) != 0)
    {
        LOG_ERROR("failed to send to global thread, " << *conn_guid << ", msg id: " << demo1005_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1006_req_msg_head = { 0, ss::MSG_ID_DEMO1006_REQ };

    ss::Demo1006Req demo1006_req;
    demo1006_req.set_a(1006);

    if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo1006_req_msg_head, &demo1006_req, -1) != 0)
    {
        LOG_ERROR("failed to send to work thread, " << *conn_guid << ", msg id: " << demo1006_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1007_req_msg_head = { 0, ss::MSG_ID_DEMO1007_REQ };

    ss::Demo1007Req demo1007_req;
    demo1007_req.set_a(1007);

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo1007_req_msg_head, &demo1007_req, -1) != 0)
    {
        LOG_ERROR("failed to send to burden thread, " << *conn_guid << ", msg id: " << demo1007_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead demo1008_req_msg_head = { 0, ss::MSG_ID_DEMO1008_REQ };

    ss::Demo1008Req demo1008_req;
    demo1008_req.set_a(1008);

    if (SendToRawTCPThread(logic_ctx_->scheduler, conn_guid, demo1008_req_msg_head, &demo1008_req, conn_guid->io_thread_idx) != 0)
    {
        LOG_ERROR("failed to send to proto tcp thread, " << *conn_guid << ", msg id: " << demo1008_req_msg_head.msg_id);
        return;
    }

    ////////////////////////////////////////////////////////////////////////////////
    logic_ctx_->scheduler->SendToClient(conn_guid, "nfy1003", strlen("nfy1003"));
}
}
