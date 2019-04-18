#ifndef DEMO_SERVER_RAW_TCP_LOGICS_DEMO1008_REQ_HANDLER_H_
#define DEMO_SERVER_RAW_TCP_LOGICS_DEMO1008_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace raw
{
class Demo1008ReqHandler : public MsgHandler
{
public:
    Demo1008ReqHandler();
    virtual ~Demo1008ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;
};
}
}

#endif // DEMO_SERVER_RAW_TCP_LOGICS_DEMO1008_REQ_HANDLER_H_
