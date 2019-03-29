#ifndef DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_H_

// 一般做一个MsgHandler的基类，放消息处理器公用的一些函数

#include "log_util.h"
#include "protobuf_util.h"
#include "the_global_logic_interface.h"
#include "work_common_logic_interface.h"
#include "work_msg_handler_interface.h"
#include "work_scheduler_interface.h"

namespace work
{
class Logic;

class MsgHandler : public MsgHandlerInterface
{
public:
    MsgHandler();
    virtual ~MsgHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    int Initialize(const void* ctx) override;

    void SetGlobalLogic(global::TheLogicInterface* global_logic)
    {
        global_logic_ = global_logic;
    }

    void SetLogic(Logic* logic)
    {
        logic_ = logic;
    }

    void SendToWorkThread(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
                          const google::protobuf::Message* protobuf_msg, int work_thread_idx)
    {
        char* msg_body = nullptr;
        size_t msg_body_len = 0;

        if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
        {
            LOG_ERROR("failed to serial msg");
            return;
        }

        logic_ctx_->scheduler->SendToWorkThread(conn_guid, msg_head, msg_body, msg_body_len, work_thread_idx);
        FreeProtobufMsgBuf(&msg_body);
    }

    void SendToClient(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head, const google::protobuf::Message* protobuf_msg)
    {
        char* msg_body = nullptr;
        size_t msg_body_len = 0;

        if (SerializeProtobufMsg(&msg_body, msg_body_len, protobuf_msg) != 0)
        {
            LOG_ERROR("failed to serial msg");
            return;
        }

        logic_ctx_->scheduler->SendToClient(conn_guid, msg_head, msg_body, msg_body_len);
        FreeProtobufMsgBuf(&msg_body);
    }

protected:
    global::TheLogicInterface* global_logic_;
    TheCommonLogicInterface* common_logic_;
    Logic* logic_;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_MSG_HANDLER_H_
