#include "demo_4_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "log_util.h"
#include "work_protobuf_msg_util.h"

using namespace com::moon::demo;

namespace work
{
Demo4ReqHandler::Demo4ReqHandler()
{

}

Demo4ReqHandler::~Demo4ReqHandler()
{

}

MsgId Demo4ReqHandler::GetMsgId()
{
    return proto::cs::MSG_ID_DEMO_4_REQ;
}

void Demo4ReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                            size_t msg_body_len)
{
    LOG_TRACE(
        "work::Demo4ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo4Req demo_4_req;
    if (ParseProtobufMsg(&demo_4_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msd id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    if (demo_4_req.flag() == proto::cs::DEMO_4_FLAG_IO_TO_WORK)
    {
        demo_4_req.set_flag(proto::cs::DEMO_4_FLAG_WORK_TO_WORK);

        if (SendToWorkThread(logic_ctx_->scheduler, conn_guid, msg_head, &demo_4_req, -1) != 0)
        {
            LOG_ERROR("failed to send to work thread");
            SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
            return;
        }
    }
    else if (demo_4_req.flag() == proto::cs::DEMO_4_FLAG_WORK_TO_WORK)
    {
        demo_4_req.set_flag(proto::cs::DEMO_4_FLAG_WORK_TO_BURDEN);

        if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, msg_head, &demo_4_req, -1) != 0)
        {
            LOG_ERROR("failed to send to burden thread");
            return;
        }
    }
    else
    {
        LOG_ERROR("invalid flag");
    }
}

void Demo4ReqHandler::SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const
{
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_4_RSP;

    proto::cs::Demo4Rsp demo_4_rsp;
    demo_4_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToTcpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_4_rsp);
}
}
