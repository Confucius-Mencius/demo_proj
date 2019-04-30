#include "demo303_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo303ReqHandler::Demo303ReqHandler()
{
}

Demo303ReqHandler::~Demo303ReqHandler()
{
}

::proto::MsgID Demo303ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO303_REQ;
}

void Demo303ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                              const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo303ReqHandler::OnMsg");

    ss::Demo303Req demo303_req;
    if (ParseProtobufMsg(&demo303_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_DEBUG(demo303_req.a());

    // 服务器关闭连接
    logic_ctx_->scheduler->CloseClient(conn_guid);
}

void Demo303ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = ss::MSG_ID_DEMO303_RSP;

    ss::Demo303Rsp demo303_rsp;
    demo303_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo303_rsp);
}
}
}
