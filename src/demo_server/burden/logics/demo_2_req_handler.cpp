#include "demo_2_req_handler.h"
#include "burden_protobuf_msg_util.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "log_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo2ReqHandler::Demo2ReqHandler()
{

}

Demo2ReqHandler::~Demo2ReqHandler()
{

}

MsgId Demo2ReqHandler::GetMsgId()
{
    return proto::cs::MSG_ID_DEMO_2_REQ;
}

void Demo2ReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                            size_t msg_body_len)
{
    LOG_TRACE(
        "burden::Demo2ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo2Req demo_2_req;
    if (ParseProtobufMsg(&demo_2_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_TRACE("a: " << demo_2_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    // 生成一个新任务，内部调度给其它burden线程处理
    MsgHead demo_1_msg_head = msg_head;
    demo_1_msg_head.msg_id = proto::cs::MSG_ID_DEMO_1_REQ;

    proto::cs::Demo1Req demo_1_req;
    demo_1_req.set_a(2);

    if (demo_2_req.udp())
    {
        demo_1_req.set_udp(true);
    }

    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, demo_1_msg_head, &demo_1_req, 1) != 0)
    {
        LOG_ERROR("failed to send to burden thread #1");
        SendErrRsp(conn_guid, msg_head, ERR_SYS_ERROR);
        return;
    }
}

void Demo2ReqHandler::SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const
{
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_2_RSP;

    proto::cs::Demo2Rsp demo_2_rsp;
    demo_2_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToTcpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_2_rsp);
}
}
