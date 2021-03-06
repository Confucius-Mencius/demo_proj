#ifndef PROTO_SRC_WORK_PROTOBUF_UTIL_H_
#define PROTO_SRC_WORK_PROTOBUF_UTIL_H_

#include "conn.h"
#include "proto_msg.h"
#include "proto_msg_codec.h"
#include "protobuf_util.h"
#include "work_scheduler_interface.h"

inline int SendToClient(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                        const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToClient(conn_guid, msg_head, msg_body, msg_body_len);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}


inline int BroadcastToClient(work::SchedulerInterface* scheduler, ::proto::MsgCodec* msg_codec,
                             const std::vector<ConnGUID*>& conn_guid_vec, const ::proto::MsgHead& msg_head,
                             const google::protobuf::Message* protobuf_msg)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = -1;

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

        if (msg_codec->EncodeMsg(&data, len, msg_head, msg_body, msg_body_len) != 0)
        {
            break;
        }

        for (const auto& conn_guid : conn_guid_vec)
        {
            scheduler->SendToClient(conn_guid, data, len);
        }

        ret = 0;
    } while (0);

    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline int SendToGlobalThread(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                              const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToGlobalThread(conn_guid, msg_head, msg_body, msg_body_len);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline int SendToWorkThread(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                            const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg,
                            int work_thread_idx)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToWorkThread(conn_guid, msg_head, msg_body, msg_body_len, work_thread_idx);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline int SendToBurdenThread(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                              const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg,
                              int burden_thread_idx)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToBurdenThread(conn_guid, msg_head, msg_body, msg_body_len, burden_thread_idx);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline int SendToTCPThread(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                           const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg,
                           int tcp_thread_idx)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToTCPThread(conn_guid, msg_head, msg_body, msg_body_len, tcp_thread_idx);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline int SendToProtoTCPThread(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                                const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg,
                                int proto_tcp_thread_idx)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToProtoTCPThread(conn_guid, msg_head, msg_body, msg_body_len, proto_tcp_thread_idx);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline int SendToWebThread(work::SchedulerInterface* scheduler, const ConnGUID* conn_guid,
                           const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg,
                           int web_thread_idx)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return -1;
    }

    int ret = scheduler->SendToWebThread(conn_guid, msg_head, msg_body, msg_body_len, web_thread_idx);
    FreeProtobufMsgBuf(&msg_body);
    return ret;
}

inline TransID SendToServer(work::SchedulerInterface* scheduler, const Peer& peer, const ::proto::MsgHead& msg_head,
                            const google::protobuf::Message* protobuf_msg, const AsyncCtx* async_ctx)
{
    char* msg_body = nullptr;
    size_t msg_body_len = 0;

    if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
    {
        LOG_ERROR("failed to serial msg, msg id: " << msg_head.msg_id);
        return INVALID_TRANS_ID;
    }

    TransID trans_id = scheduler->SendToServer(peer, msg_head, msg_body, msg_body_len, async_ctx);
    FreeProtobufMsgBuf(&msg_body);
    return trans_id;
}

#endif // PROTO_SRC_WORK_PROTOBUF_UTIL_H_
