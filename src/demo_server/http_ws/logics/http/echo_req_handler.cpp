#include "echo_req_handler.h"
#include "http_rsp_maker.h"
#include "http_ws_scheduler_interface.h"
#include "log_util.h"

namespace tcp
{
namespace http_ws
{
namespace http
{
EchoReqHandler::EchoReqHandler()
{
}

EchoReqHandler::~EchoReqHandler()
{
}

const char* EchoReqHandler::GetPath()
{
    return "/echo";
}

void EchoReqHandler::OnPost(const ConnGUID* conn_guid, const char* client_ip,
                            const QueryMap& queries, const HeaderMap& headers,
                            const char* body, size_t len)
{
    tcp::http_ws::http::RspMaker http_rsp_maker;
    const std::string http_rsp = http_rsp_maker.SetStatusCode(HTTP_STATUS_OK)
                                 .SetContentType("text/plain;charset=UTF-8")
                                 .MakeRsp(body, len);

    logic_ctx_->scheduler->SendToClient(conn_guid, http_rsp.data(), http_rsp.size());
}
}
}
}
