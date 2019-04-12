#ifndef DEMO_SERVER_HTTP_WS_LOGICS_ECHO_REQ_HANDLER_H_
#define DEMO_SERVER_HTTP_WS_LOGICS_ECHO_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace http_ws
{
namespace http
{
class EchoReqHandler : public MsgHandler
{
public:
    EchoReqHandler();
    virtual ~EchoReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    const char* GetPath() override;
    void OnPost(const ConnGUID* conn_guid, const char* client_ip,
                const QueryMap& queries, const HeaderMap& headers,
                const char* body, size_t len) override;
};
}
}
}

#endif // DEMO_SERVER_HTTP_WS_LOGICS_ECHO_REQ_HANDLER_H_
