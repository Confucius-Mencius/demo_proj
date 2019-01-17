#include "echo_req_handler.h"
#include <evhttp.h>
#include "http_logic_interface.h"
#include "log_util.h"

namespace http
{
EchoReqHandler::EchoReqHandler()
{

}

EchoReqHandler::~EchoReqHandler()
{

}

const char* EchoReqHandler::GetHttpReqPath()
{
    return "/echo";
}

void EchoReqHandler::OnHttpHeadReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                                   const KeyValMap* http_header_map, const KeyValMap* http_query_map)
{
}

void EchoReqHandler::OnHttpGetReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                                  const KeyValMap* http_header_map, const KeyValMap* http_query_map)
{
    LOG_TRACE("http::EchoReqHandler::OnMsg, " << conn_guid);
    logic_ctx_->scheduler->SendToClient(conn_guid, evhttp_req, HTTP_OK, NULL, NULL, 0);
}

void EchoReqHandler::OnHttpPostReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                                   const KeyValMap* http_header_map, const KeyValMap* http_query_map, const char* data,
                                   int data_len)
{
    LOG_TRACE("http::EchoReqHandler::OnMsg, " << conn_guid);
    logic_ctx_->scheduler->SendToClient(conn_guid, evhttp_req, HTTP_OK, NULL, data, data_len);
}

void EchoReqHandler::OnHttpPutReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                                  const KeyValMap* http_header_map, const KeyValMap* http_query_map, const char* data,
                                  int data_len)
{
}
}
