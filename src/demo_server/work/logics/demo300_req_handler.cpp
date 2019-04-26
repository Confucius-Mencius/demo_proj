#include "demo300_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo300ReqHandler::Demo300ReqHandler()
{
}

Demo300ReqHandler::~Demo300ReqHandler()
{
}

::proto::MsgID Demo300ReqHandler::GetMsgID()
{
    return cs::MSG_ID_DEMO300_REQ;
}

void Demo300ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnMsg");

    cs::Demo300Req demo300_req;
    if (ParseProtobufMsg(&demo300_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_DEBUG(demo300_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    {
        ::proto::MsgHead req301_msg_head = msg_head;
        req301_msg_head.msg_id = ss::MSG_ID_DEMO301_REQ;

        ss::Demo301Req demo301_req;
        demo301_req.set_a(301);

        Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 6666 };

        AsyncCtx async_ctx;
        async_ctx.sink = this;
        async_ctx.data = conn_guid; // 内部会拷贝一份
        async_ctx.len = sizeof(ConnGUID);

        TransID trans_id = SendToServer(logic_ctx_->scheduler, peer, req301_msg_head, &demo301_req, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to send to server, " << peer << ", msg id: " << req301_msg_head.msg_id);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
    }

    ////////////////////////////////////////////////////////////////////////////////
    {
        ::proto::MsgHead req302_msg_head = msg_head;
        req302_msg_head.msg_id = ss::MSG_ID_DEMO302_REQ;

        ss::Demo302Req demo302_req;
        demo302_req.set_a(302);

        Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 6666 };

        AsyncCtx async_ctx;
        async_ctx.sink = this;
        async_ctx.timeout_sec = 1;

        TransID trans_id = SendToServer(logic_ctx_->scheduler, peer, req302_msg_head, &demo302_req, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to send to server, " << peer << ", msg id: " << req302_msg_head.msg_id);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
    }
}

void Demo300ReqHandler::OnConnected(TransID trans_id, const Peer& peer, const void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnConnected, trans id: " << trans_id);
}

void Demo300ReqHandler::OnClosed(TransID trans_id, const Peer& peer, const void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnClosed, trans id: " << trans_id);
}

void Demo300ReqHandler::OnRecvRsp(TransID trans_id, const Peer& peer, const proto::MsgHead& msg_head,
                                  const void* msg_body, size_t msg_body_len, const void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnRecvRsp, trans id: " << trans_id);

    if (len != sizeof(ConnGUID))
    {
        LOG_ERROR("invalid len: " << len);
        return;
    }

    const ConnGUID* conn_guid = (const ConnGUID*) data;

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO300_RSP;

    cs::Demo300Rsp demo300_rsp;
    demo300_rsp.mutable_err_ctx()->set_err_code(ERR_OK);

    if (SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo300_rsp) != 0)
    {
        LOG_ERROR("failed to send to client, " << conn_guid << ", msg id: " << rsp_msg_head.msg_id);
        return;
    }
}

void Demo300ReqHandler::OnRecvHTTPRsp(TransID trans_id, const Peer& peer, const http::Rsp* http_rsp, const void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnRecvHTTPRsp, trans id: " << trans_id);
}

void Demo300ReqHandler::OnTimeout(TransID trans_id, const Peer& peer, const void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnTimeout, trans id: " << trans_id);
}

void Demo300ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO300_RSP;

    cs::Demo300Rsp demo300_rsp;
    demo300_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo300_rsp);
}
}
