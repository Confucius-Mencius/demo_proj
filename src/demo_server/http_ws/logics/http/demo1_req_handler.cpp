#include "demo1_req_handler.h"
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
Demo1ReqHandler::Demo1ReqHandler()
{
}

Demo1ReqHandler::~Demo1ReqHandler()
{
}

const char* Demo1ReqHandler::GetPath()
{
    return "/demo1";
}

void Demo1ReqHandler::OnGet(const ConnGUID* conn_guid, const char* client_ip, const QueryMap& queries, const HeaderMap& headers)
{
    LOG_TRACE("tcp::http_ws::http::Demo1ReqHandler::OnGet");

    ::http::RspMaker http_rsp_maker;
    const std::string http_rsp = http_rsp_maker.SetStatusCode(HTTP_STATUS_OK)
                                 .SetContentType("text/plain;charset=UTF-8")
                                 .MakeRsp("hello, world", strlen("hello, world"));

    logic_ctx_->scheduler->SendToClient(conn_guid, http_rsp.data(), http_rsp.size());
}

void Demo1ReqHandler::OnPost(const ConnGUID* conn_guid, const char* client_ip,
                            const QueryMap& queries, const HeaderMap& headers,
                            const char* body, size_t len)
{
    LOG_TRACE("tcp::http_ws::http::Demo1ReqHandler::OnPost");

    ::http::RspMaker http_rsp_maker;
    const std::string http_rsp = http_rsp_maker.SetStatusCode(HTTP_STATUS_OK)
                                 .SetContentType("text/plain;charset=UTF-8")
                                 .MakeRsp(body, len);

    logic_ctx_->scheduler->SendToClient(conn_guid, http_rsp.data(), http_rsp.size());
}
}
}
}
