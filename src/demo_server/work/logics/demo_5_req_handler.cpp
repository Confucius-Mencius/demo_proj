#include "demo_5_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "log_util.h"
#include "work_protobuf_msg_util.h"

using namespace com::moon::demo;

namespace work
{
Demo5ReqHandler::Demo5ReqHandler()
{

}

Demo5ReqHandler::~Demo5ReqHandler()
{

}

MsgId Demo5ReqHandler::GetMsgId()
{
    return proto::cs::MSG_ID_DEMO_5_REQ;
}

void Demo5ReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                            size_t msg_body_len)
{

    LOG_TRACE(
        "work::Demo5ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo5Req demo_5_req;
    if (ParseProtobufMsg(&demo_5_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_TRACE("a: " << demo_5_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    // 回复http线程
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_5_RSP;

    proto::cs::Demo5Rsp demo_5_rsp;
    demo_5_rsp.mutable_err_ctx()->set_err_code(ERR_OK);

    if (SendToHttpThread(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_5_rsp, conn_guid->io_thread_idx) != 0)
    {
        LOG_ERROR("failed to send to http thread");
        return;
    }
}

void Demo5ReqHandler::SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const
{
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_5_RSP;

    proto::cs::Demo5Rsp demo_5_rsp;
    demo_5_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToHttpThread(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_5_rsp, conn_guid->io_thread_idx);
}
}
