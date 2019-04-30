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
        async_ctx.data = (void*) conn_guid; // 内部会拷贝一份
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
        async_ctx.timeout_sec = 2;
        async_ctx.data = (void*) "timeout-proto-tcp";
        async_ctx.len = strlen("timeout-proto-tcp");

        TransID trans_id = SendToServer(logic_ctx_->scheduler, peer, req302_msg_head, &demo302_req, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to send to server, " << peer << ", msg id: " << req302_msg_head.msg_id);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
        my_trans_id_map_.insert(MyTransIDMap::value_type(trans_id, "proto-tcp"));
    }

    ////////////////////////////////////////////////////////////////////////////////
    {
        Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 10080 };

        ::http::GetParams get_params;
        get_params.uri = "/demo1";

        AsyncCtx async_ctx;
        async_ctx.sink = this;
        async_ctx.data = (void*) conn_guid; // 内部会拷贝一份
        async_ctx.len = sizeof(ConnGUID);

        TransID trans_id = logic_ctx_->scheduler->HTTPGet(peer, get_params, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to do http get, " << peer);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
    }

    ////////////////////////////////////////////////////////////////////////////////
    {
        Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 10080 };

        ::http::PostParams post_params;
        post_params.get_params.uri = "/demo1";
        post_params.data = "hello, world";
        post_params.len = strlen("hello, world");

        AsyncCtx async_ctx;
        async_ctx.sink = this;
        async_ctx.data = (void*) conn_guid; // 内部会拷贝一份
        async_ctx.len = sizeof(ConnGUID);

        TransID trans_id = logic_ctx_->scheduler->HTTPPost(peer, post_params, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to do http post, " << peer);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
    }

    ////////////////////////////////////////////////////////////////////////////////
    {
        Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 10080 };

        ::http::GetParams get_params;
        get_params.uri = "/demo2";

        AsyncCtx async_ctx;
        async_ctx.sink = this;
        async_ctx.timeout_sec = 2;
        async_ctx.data = (void*) "timeout-http-get";
        async_ctx.len = strlen("timeout-http-get");

        TransID trans_id = logic_ctx_->scheduler->HTTPGet(peer, get_params, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to do http get, " << peer);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
    }

    ////////////////////////////////////////////////////////////////////////////////
    {
        Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 10080 };

        ::http::PostParams post_params;
        post_params.get_params.uri = "/demo2";
        post_params.data = "hello, world";
        post_params.len = strlen("hello, world");

        AsyncCtx async_ctx;
        async_ctx.sink = this;
        async_ctx.timeout_sec = 2;
        async_ctx.data = (void*) "timeout-http-post";
        async_ctx.len = strlen("timeout-http-post");

        TransID trans_id = logic_ctx_->scheduler->HTTPPost(peer, post_params, &async_ctx);
        if (INVALID_TRANS_ID == trans_id)
        {
            LOG_ERROR("failed to do http post, " << peer);
            return;
        }

        LOG_DEBUG("trans id: " << trans_id);
        my_trans_id_map_.insert(MyTransIDMap::value_type(trans_id, "http-post"));
    }
}

void Demo300ReqHandler::OnConnected(TransID trans_id, const Peer& peer, void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnConnected, trans id: " << trans_id);
}

void Demo300ReqHandler::OnClosed(TransID trans_id, const Peer& peer, void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnClosed, trans id: " << trans_id);
}

void Demo300ReqHandler::OnRecvRsp(TransID trans_id, const Peer& peer, const proto::MsgHead& msg_head,
                                  const void* msg_body, size_t msg_body_len, void* data, size_t len)
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

void Demo300ReqHandler::OnRecvHTTPRsp(TransID trans_id, const Peer& peer, const http::Rsp* http_rsp, void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnRecvHTTPRsp, trans id: " << trans_id);
    LOG_DEBUG("status code: " << http_rsp->status_code << ", " << http_rsp->rsp_body); // demo1 or or demo3

    for (http::HeaderMap::const_iterator cit = http_rsp->headers->begin(); cit != http_rsp->headers->end(); ++cit)
    {
        LOG_DEBUG("key: " << cit->first << ", value: " << cit->second);
    }

    if (len != sizeof(ConnGUID))
    {
        LOG_ERROR("invalid len: " << len);
        return;
    }

    const ConnGUID* conn_guid = (const ConnGUID*) data;

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead rsp_msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO300_RSP;

    cs::Demo300Rsp demo300_rsp;
    demo300_rsp.mutable_err_ctx()->set_err_code(ERR_OK);

    if (SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo300_rsp) != 0)
    {
        LOG_ERROR("failed to send to client, " << conn_guid << ", msg id: " << rsp_msg_head.msg_id);
        return;
    }
}

void Demo300ReqHandler::OnTimeout(TransID trans_id, const Peer& peer, void* data, size_t len)
{
    LOG_TRACE("work::Demo300ReqHandler::OnTimeout, trans id: " << trans_id);

    if (data != nullptr && len > 0)
    {
        LOG_DEBUG("data: " << data << ", len: " << len);
    }

    // 如果记录过，则发送303
    MyTransIDMap::const_iterator cit = my_trans_id_map_.find(trans_id);
    if (cit != my_trans_id_map_.end())
    {
        if (0 == strcmp("proto-tcp", cit->second.c_str()))
        {
            ::proto::MsgHead req303_msg_head;
            req303_msg_head.msg_id = ss::MSG_ID_DEMO303_REQ;

            ss::Demo303Req demo303_req;
            demo303_req.set_a(303);

            Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 6666 };

            AsyncCtx async_ctx;
            async_ctx.sink = this;

            TransID trans_id = SendToServer(logic_ctx_->scheduler, peer, req303_msg_head, &demo303_req, &async_ctx);
            if (INVALID_TRANS_ID == trans_id)
            {
                LOG_ERROR("failed to send to server, " << peer << ", msg id: " << req303_msg_head.msg_id);
                return;
            }

            LOG_DEBUG("trans id: " << trans_id);
        }
        else if (0 == strcmp("http-post", cit->second.c_str()))
        {
            Peer peer = { PEER_TYPE_PROTO_TCP, "127.0.0.1", 10080 };

            ::http::GetParams get_params;
            get_params.uri = "/demo3";

            AsyncCtx async_ctx;
            async_ctx.sink = this;

            TransID trans_id = logic_ctx_->scheduler->HTTPGet(peer, get_params, &async_ctx);
            if (INVALID_TRANS_ID == trans_id)
            {
                LOG_ERROR("failed to do http get, " << peer);
                return;
            }

            LOG_DEBUG("trans id: " << trans_id);
        }
    }
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
