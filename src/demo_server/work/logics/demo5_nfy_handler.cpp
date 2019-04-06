#include "demo5_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo5NfyHandler::Demo5NfyHandler()
{
}

Demo5NfyHandler::~Demo5NfyHandler()
{
}

::proto::MsgID Demo5NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO5_NFY;
}

void Demo5NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo5NfyHandler::OnMsg");

    ss::Demo5Nfy demo5_nfy;
    if (ParseProtobufMsg(&demo5_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo5_nfy.a());
}
}
