#include "demo_1_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "log_util.h"
#include "work_protobuf_msg_util.h"

using namespace com::moon::demo;

namespace work
{
Demo1ReqHandler::Demo1ReqHandler()
{

}

Demo1ReqHandler::~Demo1ReqHandler()
{

}

MsgId Demo1ReqHandler::GetMsgId()
{
    return proto::cs::MSG_ID_DEMO_1_REQ;
}

void Demo1ReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                            size_t msg_body_len)
{
    LOG_TRACE(
        "work::Demo1ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo1Req demo_1_req;
    if (ParseProtobufMsg(&demo_1_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_TRACE("a: " << demo_1_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    // 回复客户端
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_1_RSP;

    proto::cs::Demo1Rsp demo_1_rsp;
    demo_1_rsp.mutable_err_ctx()->set_err_code(ERR_OK);

    if (!demo_1_req.udp())
    {
        if (SendToTcpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_1_rsp) != 0)
        {
            LOG_ERROR("failed to send to " << conn_guid);
            return;
        }
    }
    else
    {
        if (SendToUdpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_1_rsp) != 0)
        {
            LOG_ERROR("failed to send to " << conn_guid);
            return;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////
    // 生成一个新任务，内部调度给其它work线程处理
    MsgHead demo_2_msg_head;
    demo_2_msg_head.msg_id = proto::cs::MSG_ID_DEMO_2_REQ;

    proto::cs::Demo2Req demo_2_req;
    demo_2_req.set_a(2);

    if (demo_1_req.udp())
    {
        demo_2_req.set_udp(true);
    }

    if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo_2_msg_head, &demo_2_req, 1) != 0)
    {
        LOG_ERROR("failed to send to work thread #1");
        return;
    }
}

void Demo1ReqHandler::SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const
{
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_1_RSP;

    proto::cs::Demo1Rsp demo_1_rsp;
    demo_1_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToTcpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_1_rsp);
}
}
