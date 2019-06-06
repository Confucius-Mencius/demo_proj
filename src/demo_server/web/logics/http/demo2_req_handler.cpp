#include "demo2_req_handler.h"
#include <string.h>
#include "http_rsp_maker.h"
#include "log_util.h"
#include "web_scheduler_interface.h"

namespace tcp
{
namespace web
{
namespace http
{
Demo2ReqHandler::Demo2ReqHandler()
{
}

Demo2ReqHandler::~Demo2ReqHandler()
{
}

const char* Demo2ReqHandler::GetPath()
{
    return "/demo2";
}

void Demo2ReqHandler::OnGet(const ConnGUID* conn_guid, const char* client_ip, const QueryMap& queries, const HeaderMap& headers)
{
    LOG_TRACE("tcp::web::http::Demo2ReqHandler::OnGet");
}

void Demo2ReqHandler::OnPost(const ConnGUID* conn_guid, const char* client_ip,
                             const QueryMap& queries, const HeaderMap& headers,
                             const char* body, size_t len)
{
    LOG_TRACE("tcp::web::http::Demo2ReqHandler::OnPost");
}
}
}
}
