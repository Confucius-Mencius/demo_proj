#ifndef DEMO_SERVER_HTTP_LOGICS_ECHO_REQ_HANDLER_H_
#define DEMO_SERVER_HTTP_LOGICS_ECHO_REQ_HANDLER_H_

#include "msg_handler.h"

namespace http
{
class EchoReqHandler : public MsgHandler
{
public:
    EchoReqHandler();
    virtual ~EchoReqHandler();

    ///////////////////////// http::MsgHandlerInterface /////////////////////////
    const char* GetHttpReqPath() override;

    void OnHttpHeadReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                       const KeyValMap* http_header_map, const KeyValMap* http_query_map) override;
    void OnHttpGetReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                      const KeyValMap* http_header_map, const KeyValMap* http_query_map) override;
    void OnHttpPostReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                       const KeyValMap* http_header_map, const KeyValMap* http_query_map, const char* data,
                       int data_len) override;
    void OnHttpPutReq(const ConnGuid* conn_guid, struct evhttp_request* evhttp_req, bool https,
                      const KeyValMap* http_header_map, const KeyValMap* http_query_map, const char* data,
                      int data_len) override;
};
}

#endif // DEMO_SERVER_HTTP_LOGICS_ECHO_REQ_HANDLER_H_
