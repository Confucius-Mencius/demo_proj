#ifndef DEMO_SERVER_WEB_LOGICS_DEMO2_REQ_HANDLER_H_
#define DEMO_SERVER_WEB_LOGICS_DEMO2_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace web
{
namespace http
{
class Demo2ReqHandler : public MsgHandler
{
public:
    Demo2ReqHandler();
    virtual ~Demo2ReqHandler();

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

#endif // DEMO_SERVER_WEB_LOGICS_DEMO2_REQ_HANDLER_H_
