#include "demo1090_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo1090ReqHandler::Demo1090ReqHandler()
{
}

Demo1090ReqHandler::~Demo1090ReqHandler()
{
}

::proto::MsgID Demo1090ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1090_REQ;
}

void Demo1090ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo1090ReqHandler::OnMsg");

    ss::Demo1090Req demo1090_req;
    if (ParseProtobufMsg(&demo1090_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1090_req.a());
}
}
