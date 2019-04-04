#include "demo4_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo4NfyHandler::Demo4NfyHandler()
{
}

Demo4NfyHandler::~Demo4NfyHandler()
{
}

::proto::MsgID Demo4NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO4_NFY;
}

void Demo4NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo4NfyHandler::OnMsg");

    ss::Demo4Nfy demo4_nfy;
    if (ParseProtobufMsg(&demo4_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    // TODO
}
}
