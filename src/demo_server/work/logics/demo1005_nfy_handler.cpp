#include "demo1005_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo1005NfyHandler::Demo1005NfyHandler()
{
}

Demo1005NfyHandler::~Demo1005NfyHandler()
{
}

::proto::MsgID Demo1005NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1005_NFY;
}

void Demo1005NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("work::Demo1005NfyHandler::OnMsg");

    ss::Demo1005Nfy demo1005_nfy;
    if (ParseProtobufMsg(&demo1005_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1005_nfy.a());
}
}
