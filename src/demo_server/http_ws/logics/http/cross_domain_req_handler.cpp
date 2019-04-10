#include "cross_domain_req_handler.h"
#include "http_rsp_maker.h"
#include "http_ws_scheduler_interface.h"
#include "log_util.h"

namespace tcp
{
namespace http
{
CrossDomainReqHandler::CrossDomainReqHandler()
{
}

CrossDomainReqHandler::~CrossDomainReqHandler()
{
}

const char* CrossDomainReqHandler::GetPath()
{
    return "/crossdomain.xml";
}

void CrossDomainReqHandler::OnGet(const ConnGUID* conn_guid, const char* client_ip,
                                  const QueryParams& query_params, const Headers& headers)
{
    static const char flash_policy[] = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
                                       "<cross-domain-policy>\n"
                                       "<allow-access-from domain=\"*\"/>\n"
                                       "</cross-domain-policy>";
    static const size_t flash_policy_len = strlen(flash_policy);

    tcp::http::RspMaker rsp_maker;
    const std::string http_rsp = rsp_maker.SetContentType("text/xml;charset=UTF-8").MakeRsp(flash_policy, flash_policy_len);

    logic_ctx_->scheduler->SendToClient(conn_guid, http_rsp.data(), http_rsp.size());
}
}
}
