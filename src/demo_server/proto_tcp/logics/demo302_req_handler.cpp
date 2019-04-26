#include "demo302_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo302ReqHandler::Demo302ReqHandler()
{
}

Demo302ReqHandler::~Demo302ReqHandler()
{
}

::proto::MsgID Demo302ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO302_REQ;
}

void Demo302ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                              const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo302ReqHandler::OnMsg");

    ss::Demo302Req demo302_req;
    if (ParseProtobufMsg(&demo302_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_DEBUG(demo302_req.a());
}

void Demo302ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = ss::MSG_ID_DEMO302_RSP;

    ss::Demo302Rsp demo302_rsp;
    demo302_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo302_rsp);
}
}
}
