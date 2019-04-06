#include "demo9_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "burden_protobuf_util.h"

using namespace com::moon::demo;

namespace burden
{
Demo9NfyHandler::Demo9NfyHandler()
{
}

Demo9NfyHandler::~Demo9NfyHandler()
{
}

::proto::MsgID Demo9NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO9_NFY;
}

void Demo9NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("burden::Demo9NfyHandler::OnMsg");

    ss::Demo9Nfy demo9_nfy;
    if (ParseProtobufMsg(&demo9_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo9_nfy.a());
}
}
