#ifndef DEMO_SERVER_WEB_LOGICS_DEMO1_REQ_HANDLER_H_
#define DEMO_SERVER_WEB_LOGICS_DEMO1_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace web
{
namespace http
{
class Demo1ReqHandler : public MsgHandler
{
public:
    Demo1ReqHandler();
    virtual ~Demo1ReqHandler();

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

#endif // DEMO_SERVER_WEB_LOGICS_DEMO1_REQ_HANDLER_H_
