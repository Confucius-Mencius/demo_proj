#ifndef PROTO_SRC_GLOBAL_PROTOBUF_UTIL_H_
#define PROTO_SRC_GLOBAL_PROTOBUF_UTIL_H_

#include "conn.h"
#include "proto_msg.h"
#include "protobuf_util.h"
#include "global_scheduler_interface.h"

inline int SendToWorkThread(global::SchedulerInterface* scheduler, const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                            const google::protobuf::Message* protobuf_msg, int work_thread_idx)
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

inline int SendToBurdenThread(global::SchedulerInterface* scheduler, const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                              const google::protobuf::Message* protobuf_msg, int burden_thread_idx)
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

inline int SendToProtoTCPThread(global::SchedulerInterface* scheduler, const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                                const google::protobuf::Message* protobuf_msg, int proto_tcp_thread_idx)
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

#endif // PROTO_SRC_GLOBAL_PROTOBUF_UTIL_H_
