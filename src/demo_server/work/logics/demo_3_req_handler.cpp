#include "demo_3_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "log_util.h"
#include "work_protobuf_msg_util.h"

using namespace com::moon::demo;

namespace work
{
Demo3ReqHandler::Demo3ReqHandler()
{

}

Demo3ReqHandler::~Demo3ReqHandler()
{

}

MsgId Demo3ReqHandler::GetMsgId()
{
    return proto::cs::MSG_ID_DEMO_3_REQ;
}

void Demo3ReqHandler::OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
                            size_t msg_body_len)
{
    LOG_TRACE(
        "work::Demo3ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    proto::cs::Demo3Req demo_3_req;
    if (ParseProtobufMsg(&demo_3_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_TRACE("a: " << demo_3_req.a());

    // 远程
    Peer peer;

    if (!demo_3_req.udp())
    {
        peer = {PEER_TYPE_TCP, global_logic_->GetConfMgr()->GetRemoteTcpAddrPort()};
    }
    else
    {
        peer = {PEER_TYPE_UDP, global_logic_->GetConfMgr()->GetRemoteUdpAddrPort()};
    }

    base::AsyncCtx async_ctx;
    async_ctx.timeout_sec = 60;
    async_ctx.sink = this;

    TransId trans_id = SendToServer(logic_ctx_->scheduler, peer, msg_head, &demo_3_req, &async_ctx);
    if (trans_id != INVALID_TRANS_ID)
    {
        LOG_TRACE("send to " << peer << " ok, trans id: " << trans_id);
    }

    // 派发给burden线程处理
    if (SendToBurdenThread(logic_ctx_->scheduler, conn_guid, msg_head, &demo_3_req, -1) != 0)
    {
        LOG_ERROR("failed to send to burden thread");
        return;
    }
}

void Demo3ReqHandler::OnConnected(TransId trans_id, const Peer& peer, const void* async_data, size_t async_data_len)
{
    LOG_TRACE("work::Demo3ReqHandler::OnConnected, trans id: " << trans_id << ", " << peer);
}

void Demo3ReqHandler::OnClosed(TransId trans_id, const Peer& peer, const void* async_data, size_t async_data_len)
{
    LOG_TRACE("work::Demo3ReqHandler::OnClosed, trans id: " << trans_id << ", " << peer);
}

void Demo3ReqHandler::OnRecvRsp(TransId trans_id, const Peer& peer, const MsgHead& msg_head, const void* msg_body,
                                size_t msg_body_len, const void* async_data, size_t async_data_len)
{
    LOG_TRACE("work::Demo3ReqHandler::OnRecvRsp, trans id: " << trans_id << ", " << peer);
}

void Demo3ReqHandler::OnRecvRsp(TransId trans_id, const Peer& peer, const http::Rsp* http_rsp, const void* async_data,
                                size_t async_data_len)
{
    LOG_TRACE("work::Demo3ReqHandler::OnRecvRsp, trans id: " << trans_id << ", " << peer);
}

void Demo3ReqHandler::OnTimeout(TransId trans_id, const Peer& peer, const void* async_data, size_t async_data_len)
{
    LOG_TRACE("work::Demo3ReqHandler::OnTimeout, trans id: " << trans_id << ", " << peer);
}

void Demo3ReqHandler::SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const
{
    MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = proto::cs::MSG_ID_DEMO_3_RSP;

    proto::cs::Demo3Rsp demo_3_rsp;
    demo_3_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToTcpClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_3_rsp);
}
}
