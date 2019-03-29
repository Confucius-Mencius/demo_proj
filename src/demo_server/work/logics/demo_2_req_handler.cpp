#include "demo_2_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "log_util.h"
#include "work_protobuf_msg_util.h"

using namespace com::moon::demo;

namespace work
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
        "work::Demo2ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo2Req demo_2_req;
    if (ParseProtobufMsg(&demo_2_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_TRACE("a: " << demo_2_req.a());

    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_2_RSP;

    proto::cs::Demo2Rsp demo_2_rsp;
    demo_2_rsp.mutable_err_ctx()->set_err_code(ERR_OK);


    if (!demo_2_req.udp())
    {
        if (SendToTcpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_2_rsp) != 0)
        {
            LOG_ERROR("failed to send to " << conn_guid);
            return;
        }
    }
    else
    {
        if (SendToUdpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_2_rsp) != 0)
        {
            LOG_ERROR("failed to send to " << conn_guid);
            return;
        }
    }

    // 派发给burden线程
    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, msg_head, &demo_2_req, -1) != 0)
    {
        LOG_ERROR("failed to send to burden thread");
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
