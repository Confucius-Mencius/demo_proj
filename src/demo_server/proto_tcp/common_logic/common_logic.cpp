#include "common_logic.h"
#include "ss_msg.pb.h"
#include "ss_msg_id.pb.h"
#include "proto_msg_codec.h"
#include "proto_tcp_protobuf_util.h"

using namespace com::moon::demo;

namespace tcp
{
namespace proto
{
enum
{
    SEND_NFY_TIMER_ID = 1,
};

CommonLogic::CommonLogic()
{
}

CommonLogic::~CommonLogic()
{
}

const char* CommonLogic::GetVersion() const
{
    return nullptr;
}

const char* CommonLogic::GetLastErrMsg() const
{
    return nullptr;
}

void CommonLogic::Release()
{
    delete this;
}

int CommonLogic::Initialize(const void* ctx)
{
    if (LogicInterface::Initialize(ctx) != 0)
    {
        return -1;
    }

    return 0;
}

void CommonLogic::Finalize()
{
}

int CommonLogic::Activate()
{
    return 0;
}

void CommonLogic::Freeze()
{
    logic_ctx_.timer_axis->KillTimer(this, SEND_NFY_TIMER_ID);
}

void CommonLogic::OnStop()
{
    can_exit_ = true;
}

void CommonLogic::OnReload()
{
}

void CommonLogic::OnClientConnected(const ConnGUID* conn_guid)
{
    conn_set_.insert(*conn_guid);
}

void CommonLogic::OnClientClosed(const ConnGUID* conn_guid)
{
    conn_set_.erase(*conn_guid);
}

int CommonLogic::StartSendNfyTimer(const ConnGUID* conn_guid)
{
    LOG_TRACE("tcp::proto::CommonLogic::StartSendNfyTimer, " << *conn_guid);

    if (logic_ctx_.thread_idx == conn_guid->io_thread_idx
            && !logic_ctx_.timer_axis->TimerExist(this, SEND_NFY_TIMER_ID))
    {
        // 只在一个线程中起定时器
        struct timeval interval = {1, 0};
        if (logic_ctx_.timer_axis->SetTimer(this, SEND_NFY_TIMER_ID, interval) != 0)
        {
            LOG_ERROR("failed to start send nfy timer");
            return -1;
        }
    }

    return 0;
}

void CommonLogic::OnTimer(TimerID timer_id, void* data, size_t len, int times)
{
    ::proto::MsgHead msg_head;
    msg_head.passback = NFY_PASSBACK;
    msg_head.msg_id = ss::MSG_ID_DEMO301_NFY;

    ss::Demo301Nfy demo301_nfy;
    demo301_nfy.set_a(301);

    // 这种广播，先序列化好，避免重复序列化一样的消息
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, &demo301_nfy) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return;
    }

    do
    {
        std::unique_ptr<char []> buf(new char[MIN_DATA_LEN + msg_body_len + 1]);
        if (nullptr == buf)
        {
            LOG_ERROR("failed to alloc memory");
            break;
        }

        char* data = buf.get();
        size_t len;

        if (logic_ctx_.msg_codec->EncodeMsg(&data, len, msg_head, msg_body, msg_body_len) != 0)
        {
            break;
        }

        for (ConnSet::const_iterator cit = conn_set_.cbegin(); cit != conn_set_.cend(); ++cit)
        {
            logic_ctx_.scheduler->SendToClient(&(*cit), data, len);
        }
    } while (0);

    FreeProtobufMsgBuf(&msg_body);
}
}
}
