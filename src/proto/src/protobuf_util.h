#ifndef PROTO_SRC_PROTOBUF_UTIL_H_
#define PROTO_SRC_PROTOBUF_UTIL_H_

#include <google/protobuf/message.h>
#include "log_util.h"

inline int ParseProtobufMsg(google::protobuf::Message* protobuf_msg, const void* msg, size_t len)
{
    if (nullptr == protobuf_msg || nullptr == msg || 0 == len)
    {
        return -1;
    }

    if (!protobuf_msg->ParseFromArray(msg, len))
    {
        LOG_ERROR("failed to parse msg, len: " << len);
        return -1;
    }

    return 0;
}

// 返回的msg指针需要调用FreeProtobufMsgBuf释放
inline int SerializeProtobufMsg(char** msg, size_t& len, const google::protobuf::Message* protobuf_msg)
{
    if (nullptr == protobuf_msg)
    {
        return 0;
    }

    len = protobuf_msg->ByteSize();
    char* buf = new char[len];
    if (nullptr == buf)
    {
        LOG_ERROR("failed to alloc memory");
        return -1;
    }

    if (!protobuf_msg->SerializeToArray(buf, len))
    {
        LOG_ERROR("failed to serial msg");
        delete[] buf;
        return -1;
    }

    *msg = buf;
    return 0;
}

inline void FreeProtobufMsgBuf(char** msg)
{
    if (*msg != nullptr)
    {
        delete[] (*msg);
        *msg = nullptr;
    }
}

#endif // PROTO_SRC_PROTOBUF_UTIL_H_
