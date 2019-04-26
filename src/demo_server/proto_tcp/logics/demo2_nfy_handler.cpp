#include "demo2_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
Demo2NfyHandler::Demo2NfyHandler()
{
}

Demo2NfyHandler::~Demo2NfyHandler()
{
}

::proto::MsgID Demo2NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO2_NFY;
}

void Demo2NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("tcp::proto::Demo2NfyHandler::OnMsg");

    ss::Demo2Nfy demo2_nfy;
    if (ParseProtobufMsg(&demo2_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo2_nfy.a());
}
}
}
