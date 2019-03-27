#ifndef PROTO_SRC_PROTOBUF_UTIL_H_
#define PROTO_SRC_PROTOBUF_UTIL_H_

#include <google/protobuf/message.h>

inline int ParseProtobufMsg(google::protobuf::Message* protobuf_msg, const void* msg, size_t len)
{
    if (NULL == protobuf_msg || NULL == msg || 0 == len)
    {
        return -1;
    }

    return protobuf_msg->ParseFromArray(msg, len) ? 0 : -1;
}

// 返回的msg指针需要调用FreeProtobufMsgBuf释放
inline int SerializeProtobufMsg(char** msg, size_t& len, const google::protobuf::Message* protobuf_msg)
{
    if (NULL == protobuf_msg)
    {
        return 0;
    }

    len = protobuf_msg->ByteSize();
    char* buf = new char[len];
    if (NULL == buf)
    {
        return -1;
    }

    if (!protobuf_msg->SerializeToArray(buf, len))
    {
        delete[] buf;
        return -1;
    }

    *msg = buf;
    return 0;
}

inline void FreeProtobufMsgBuf(char** msg)
{
    if (*msg != NULL)
    {
        delete[] (*msg);
        *msg = NULL;
    }
}

#endif // PROTO_SRC_PROTOBUF_UTIL_H_
