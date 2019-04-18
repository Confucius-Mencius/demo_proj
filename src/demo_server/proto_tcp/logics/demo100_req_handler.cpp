#include "demo100_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo100ReqHandler::Demo100ReqHandler()
{
}

Demo100ReqHandler::~Demo100ReqHandler()
{
}

::proto::MsgID Demo100ReqHandler::GetMsgID()
{
    return cs::MSG_ID_DEMO100_REQ;
}

void Demo100ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                              const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo100ReqHandler::OnMsg");

    cs::Demo100Req demo100_req;
    if (ParseProtobufMsg(&demo100_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    // 关闭连接
    logic_ctx_->scheduler->CloseClient(conn_guid);
}

void Demo100ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO100_RSP;

    cs::Demo100Rsp demo100_rsp;
    demo100_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo100_rsp);
}
}
}
