#include "crossdomain_req_handler.h"
#include <string.h>
#include "http_rsp_maker.h"
#include "http_ws_scheduler_interface.h"
#include "log_util.h"

namespace tcp
{
namespace http_ws
{
namespace http
{
CrossdomainReqHandler::CrossdomainReqHandler()
{
}

CrossdomainReqHandler::~CrossdomainReqHandler()
{
}

const char* CrossdomainReqHandler::GetPath()
{
    return "/crossdomain.xml";
}

void CrossdomainReqHandler::OnGet(const ConnGUID* conn_guid, const char* client_ip,
                                  const QueryMap& queries, const HeaderMap& headers)
{
    static const char flash_policy[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                                       "<cross-domain-policy>\n"
                                       "<allow-access-from domain=\"*\"/>\n"
                                       "</cross-domain-policy>";
    static const size_t flash_policy_len = strlen(flash_policy);

    ::http::RspMaker http_rsp_maker;
    const std::string http_rsp = http_rsp_maker.SetStatusCode(HTTP_STATUS_OK)
                                 .SetContentType("text/xml;charset=UTF-8")
                                 .MakeRsp(flash_policy, flash_policy_len);

    logic_ctx_->scheduler->SendToClient(conn_guid, http_rsp.data(), http_rsp.size());
}
}
}
}
