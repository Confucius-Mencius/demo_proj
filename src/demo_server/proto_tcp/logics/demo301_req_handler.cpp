#include "demo301_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo301ReqHandler::Demo301ReqHandler()
{
}

Demo301ReqHandler::~Demo301ReqHandler()
{
}

::proto::MsgID Demo301ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO301_REQ;
}

void Demo301ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                              const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo301ReqHandler::OnMsg");

    ss::Demo301Req demo301_req;
    if (ParseProtobufMsg(&demo301_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_DEBUG(demo301_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    ::proto::MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = ss::MSG_ID_DEMO301_RSP;

    ss::Demo301Rsp demo301_rsp;
    demo301_rsp.mutable_err_ctx()->set_err_code(ERR_OK);

    if (SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo301_rsp) != 0)
    {
        LOG_ERROR("failed to send to client, " << conn_guid << ", msg id: " << rsp_msg_head.msg_id);
        return;
    }

//    TheCommonLogicInterface* common_logic = (TheCommonLogicInterface*) logic_ctx_->common_logic;
}

void Demo301ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = ss::MSG_ID_DEMO301_RSP;

    ss::Demo301Rsp demo301_rsp;
    demo301_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo301_rsp);
}
}
}
