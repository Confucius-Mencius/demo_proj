#ifndef DEMO_SERVER_WORK_LOGICS_DEMO300_REQ_HANDLER_H_
#define DEMO_SERVER_WORK_LOGICS_DEMO300_REQ_HANDLER_H_

#include "msg_handler.h"
#include "peer_sink_interface.h"

namespace work
{
class Demo300ReqHandler : public MsgHandler, public PeerSinkInterface
{
public:
    Demo300ReqHandler();
    virtual ~Demo300ReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    ::proto::MsgID GetMsgID() override;
    void OnMsg(const ConnGUID* conn_guid, const ::proto::MsgHead& msg_head,
               const void* msg_body, size_t msg_body_len) override;

    ///////////////////////// PeerSinkInterface /////////////////////////
    void OnConnected(TransID trans_id, const Peer& peer, const void* data, size_t len) override;
    void OnClosed(TransID trans_id, const Peer& peer, const void* data, size_t len) override;
    void OnRecvRsp(TransID trans_id, const Peer& peer, const ::proto::MsgHead& msg_head,
                   const void* msg_body, size_t msg_body_len, const void* data, size_t len) override;
    void OnRecvHTTPRsp(TransID trans_id, const Peer& peer, const http::Rsp* http_rsp, const void* data, size_t len) override;
    void OnTimeout(TransID trans_id, const Peer& peer, const void* data, size_t len) override;

private:
    void SendErrRsp(const ConnGUID* conn_guid, const ::proto::MsgHead& req_msg_head, int err_code) const;
};
}

#endif // DEMO_SERVER_WORK_LOGICS_DEMO300_REQ_HANDLER_H_
