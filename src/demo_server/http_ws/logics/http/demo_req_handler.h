#ifndef DEMO_SERVER_HTTP_WS_LOGICS_DEMO_REQ_HANDLER_H_
#define DEMO_SERVER_HTTP_WS_LOGICS_DEMO_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace http_ws
{
namespace http
{
class DemoReqHandler : public MsgHandler
{
public:
    DemoReqHandler();
    virtual ~DemoReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    const char* GetPath() override;
    void OnGet(const ConnGUID* conn_guid, const char* client_ip,
               const QueryMap& queries, const HeaderMap& headers) override;
    void OnPost(const ConnGUID* conn_guid, const char* client_ip,
                const QueryMap& queries, const HeaderMap& headers,
                const char* body, size_t len) override;
};
}
}
}

#endif // DEMO_SERVER_HTTP_WS_LOGICS_DEMO_REQ_HANDLER_H_
