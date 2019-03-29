#ifndef DEMO_SERVER_WORK_LOGICS_DEMO_3_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO_3_REQ_HANDLER_H_

#include "msg_handler.h"

namespace work
{
class Demo3ReqHandler : public MsgHandler, PeerSinkInterface
{
public:
    Demo3ReqHandler();
    virtual ~Demo3ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    MsgId GetMsgId() override;
    void OnMsg(const ConnGuid* conn_guid, const MsgHead& msg_head, const void* msg_body,
               size_t msg_body_len) override;

    ///////////////////////// PeerSinkInterface /////////////////////////
    void OnConnected(TransId trans_id, const Peer& peer, const void* async_data, size_t async_data_len) override;
    void OnClosed(TransId trans_id, const Peer& peer, const void* async_data, size_t async_data_len) override;
    void OnRecvRsp(TransId trans_id, const Peer& peer, const MsgHead& msg_head, const void* msg_body,
                   size_t msg_body_len, const void* async_data, size_t async_data_len) override;
    void OnRecvRsp(TransId trans_id, const Peer& peer, const http::Rsp* http_rsp, const void* async_data,
                   size_t async_data_len) override;
    void OnTimeout(TransId trans_id, const Peer& peer, const void* async_data, size_t async_data_len) override;

private:
    void SendErrRsp(const ConnGuid* conn_guid, const MsgHead& msg_head, int err_code) const;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO_3_REQ_HANDLER_H_
