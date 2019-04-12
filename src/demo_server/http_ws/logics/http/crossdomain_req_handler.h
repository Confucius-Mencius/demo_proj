#ifndef DEMO_SERVER_HTTP_WS_LOGICS_CROSSDOMAIN_REQ_HANDLER_H_
#define DEMO_SERVER_HTTP_WS_LOGICS_CROSSDOMAIN_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace http_ws
{
namespace http
{
class CrossdomainReqHandler : public MsgHandler
{
public:
    CrossdomainReqHandler();
    virtual ~CrossdomainReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    const char* GetPath() override;
    void OnGet(const ConnGUID* conn_guid, const char* client_ip,
               const QueryMap& querys, const HeaderMap& headers) override;
};
}
}
}

#endif // DEMO_SERVER_HTTP_WS_LOGICS_CROSSDOMAIN_REQ_HANDLER_H_
