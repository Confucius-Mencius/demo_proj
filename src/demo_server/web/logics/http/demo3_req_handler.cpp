#include "demo3_req_handler.h"
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
Demo3ReqHandler::Demo3ReqHandler()
{
}

Demo3ReqHandler::~Demo3ReqHandler()
{
}

const char* Demo3ReqHandler::GetPath()
{
    return "/demo3";
}

void Demo3ReqHandler::OnGet(const ConnGUID* conn_guid, const char* client_ip, const QueryMap& queries, const HeaderMap& headers)
{
    LOG_TRACE("tcp::web::http::Demo3ReqHandler::OnGet");

    // 服务器关闭连接
    logic_ctx_->scheduler->CloseClient(conn_guid);
}

void Demo3ReqHandler::OnPost(const ConnGUID* conn_guid, const char* client_ip,
                             const QueryMap& queries, const HeaderMap& headers,
                             const char* body, size_t len)
{
    LOG_TRACE("tcp::web::http::Demo3ReqHandler::OnPost");
}
}
}
}
