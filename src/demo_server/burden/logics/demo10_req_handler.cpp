#include "demo10_req_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo10ReqHandler::Demo10ReqHandler()
{
}

Demo10ReqHandler::~Demo10ReqHandler()
{
}

::proto::MsgID Demo10ReqHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO10_REQ;
}

void Demo10ReqHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                             const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo10ReqHandler::OnMsg");

    ss::Demo10Req demo10_req;
    if (ParseProtobufMsg(&demo10_req, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo10_req.a());
}
}
