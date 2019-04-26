#include "demo200_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo200ReqHandler::Demo200ReqHandler()
{
}

Demo200ReqHandler::~Demo200ReqHandler()
{
}

::proto::MsgID Demo200ReqHandler::GetMsgID()
{
    return cs::MSG_ID_DEMO200_REQ;
}

void Demo200ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                              const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo200ReqHandler::OnMsg");

    cs::Demo200Req demo200_req;
    if (ParseProtobufMsg(&demo200_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_DEBUG(demo200_req.a());

    // 关闭连接
    logic_ctx_->scheduler->CloseClient(conn_guid);
}

void Demo200ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO200_RSP;

    cs::Demo200Rsp demo200_rsp;
    demo200_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo200_rsp);
}
}
