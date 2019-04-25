#include "demo1002_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
Demo1002NfyHandler::Demo1002NfyHandler()
{
}

Demo1002NfyHandler::~Demo1002NfyHandler()
{
}

::proto::MsgID Demo1002NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO1002_NFY;
}

void Demo1002NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                               const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::Demo1002NfyHandler::OnMsg");

    ss::Demo1002Nfy demo1002_nfy;
    if (ParseProtobufMsg(&demo1002_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_TRACE(demo1002_nfy.a());
}
}
