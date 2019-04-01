#include "demo_1_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo1ReqHandler::Demo1ReqHandler()
{

}

Demo1ReqHandler::~Demo1ReqHandler()
{

}

::proto::MsgID Demo1ReqHandler::GetMsgID()
{
    return cs::MSG_ID_DEMO_1_REQ;
}

void Demo1ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo1ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    cs::Demo1Req demo_1_req;
    if (ParseProtobufMsg(&demo_1_req, msg_body, msg_body_len) != 0)
    {
        SendErrRsp(conn_guid, msg_head, ERR_INVALID_PARAM);
        return;
    }

    LOG_TRACE("a: " << demo_1_req.a());

    ////////////////////////////////////////////////////////////////////////////////
    // 回复客户端
    ::proto::MsgHead rsp_msg_head = msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO_1_RSP;

    cs::Demo1Rsp demo_1_rsp;
    demo_1_rsp.mutable_err_ctx()->set_err_code(ERR_OK);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_1_rsp);

    ////////////////////////////////////////////////////////////////////////////////
    // 生成一个新任务，内部调度给其它work线程处理
    ::proto::MsgHead demo_2_msg_head;
    demo_2_msg_head.msg_id = cs::MSG_ID_DEMO_2_REQ;

    cs::Demo2Req demo_2_req;
    demo_2_req.set_a(2);

    if (demo_1_req.udp())
    {
        demo_2_req.set_udp(true);
    }

    SendToWorkThread(logic_ctx_->scheduler, conn_guid, demo_2_msg_head, &demo_2_req, -1);
}

void Demo1ReqHandler::SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const
{
    ::proto::MsgHead rsp_msg_head = req_msg_head;
    rsp_msg_head.msg_id = cs::MSG_ID_DEMO_1_RSP;

    cs::Demo1Rsp demo_1_rsp;
    demo_1_rsp.mutable_err_ctx()->set_err_code(err_code);

    SendToClient(logic_ctx_->scheduler, conn_guid, rsp_msg_head, &demo_1_rsp);
}
}
}
