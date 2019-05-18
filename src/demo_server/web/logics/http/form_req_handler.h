#ifndef DEMO_SERVER_WEB_LOGICS_FORM_REQ_HANDLER_H_
#define DEMO_SERVER_WEB_LOGICS_FORM_REQ_HANDLER_H_

#include "msg_handler.h"

namespace tcp
{
namespace web
{
namespace http
{
class FormReqHandler : public MsgHandler
{
public:
    FormReqHandler();
    virtual ~FormReqHandler();

    ///////////////////////// MsgHandlerInterface /////////////////////////
    const char* GetPath() override;
    void OnGet(const ConnGUID* conn_guid, const char* client_ip,
               const QueryMap& querys, const HeaderMap& headers) override;
};
}
}
}

#endif // DEMO_SERVER_WEB_LOGICS_FORM_REQ_HANDLER_H_
