#include "demo301_nfy_handler.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "err_code.h"
#include "work_protobuf_util.h"

using namespace com::moon::demo;

namespace work
{
Demo301NfyHandler::Demo301NfyHandler()
{
}

Demo301NfyHandler::~Demo301NfyHandler()
{
}

::proto::MsgID Demo301NfyHandler::GetMsgID()
{
    return ss::MSG_ID_DEMO301_NFY;
}

void Demo301NfyHandler::OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const void* msg_body, size_t msg_body_len)
{
    LOG_TRACE("Demo301NfyHandler::OnMsg");

    ss::Demo301Nfy demo301_nfy;
    if (ParseProtobufMsg(&demo301_nfy, msg_body, msg_body_len) != 0)
    {
        LOG_ERROR("failed to parse msg, msg id: " << msg_head.msg_id << ", msg body len: " << msg_body_len);
        return;
    }

    LOG_DEBUG(demo301_nfy.a());
}
}
