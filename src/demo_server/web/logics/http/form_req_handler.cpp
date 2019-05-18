#include "form_req_handler.h"
#include <string.h>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>
#include "http_rsp_maker.h"
#include "web_scheduler_interface.h"
#include "log_util.h"

namespace tcp
{
namespace web
{
namespace http
{
FormReqHandler::FormReqHandler()
{
}

FormReqHandler::~FormReqHandler()
{
}

const char* FormReqHandler::GetPath()
{
    return "/form";
}

void FormReqHandler::OnGet(const ConnGUID* conn_guid, const char* client_ip,
                           const QueryMap& queries, const HeaderMap& headers)
{
    //1,获取Document对象
    rapidjson::Document doc;
    doc.SetObject();

    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator(); //获取分配器

    //2，给doc对象赋值
    doc.AddMember("name", "张山", allocator);

    //3，将doc对象的值写入字符串
    rapidjson::StringBuffer buffer;
    //PrettyWriter<StringBuffer> writer(buffer);  //PrettyWriter是格式化的json，如果是Writer则是换行空格压缩后的json
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    doc.Accept(writer);

    LOG_DEBUG(buffer.GetString());

    ::http::RspMaker http_rsp_maker;
    const std::string http_rsp = http_rsp_maker.SetStatusCode(HTTP_STATUS_OK)
                                 .SetContentType("application/json;charset=UTF-8")
                                 .MakeRsp(buffer.GetString(), buffer.GetSize());

    logic_ctx_->scheduler->SendToClient(conn_guid, http_rsp.data(), http_rsp.size());
}
}
}
}
