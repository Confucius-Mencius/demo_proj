#include "demo_6_req_handler.h"
#include "cs_msg.pb.h"
#include "cs_msg_id.pb.h"
#include "err_code.h"
#include "global_scheduler_interface.h"
#include "log_util.h"
#include "protobuf_util.h"

using namespace com::moon::demo;

namespace global
{
Demo6ReqHandler::Demo6ReqHandler()
{

}

Demo6ReqHandler::~Demo6ReqHandler()
{

}

::proto::MsgID Demo6ReqHandler::GetMsgID()
{
    return cs::MSG_ID_DEMO_6_REQ;
}

void Demo6ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("global::Demo6ReqHandler::OnMsg, " << conn_guid << ", " << msg_head << ", msg body len: " << msg_body_len);

    cs::Demo6Req demo_6_req;
    if (ParseProtobufMsg(&demo_6_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE("a: " << demo_6_req.a());

    if (demo_6_req.http())
    {
        // 回复http线程
        ::proto::MsgHead rsp_msg_head = msg_head;
        rsp_msg_head.msg_id = cs::MSG_ID_DEMO_6_RSP;

        cs::Demo6Rsp demo_6_rsp;
        demo_6_rsp.mutable_err_ctx()->set_err_code(ERR_OK);
    }
}
}
