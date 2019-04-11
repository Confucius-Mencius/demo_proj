#ifndef DEMO_SERVER_HTTP_WS_LOGICS_LOGIC_H_
#define DEMO_SERVER_HTTP_WS_LOGICS_LOGIC_H_

#include "http_ws_logic_interface.h"
#include "http/msg_handler_mgr.h"

namespace tcp
{
namespace http_ws
{
class Logic : public LogicInterface
{
public:
    Logic();
    virtual ~Logic();

    ///////////////////////// ModuleInterface /////////////////////////
    const char* GetVersion() const override;
    const char* GetLastErrMsg() const override;
    void Release() override;
    int Initialize(const void* ctx) override;
    void Finalize() override;
    int Activate() override;
    void Freeze() override;

    ///////////////////////// ws::LogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;
    void OnClientConnected(const ConnGUID* conn_guid) override;
    void OnClientClosed(const ConnGUID* conn_guid) override;
    void OnWSMsg(const ConnGUID* conn_guid, int frame_type, const void* data, size_t len) override;

private:
    tcp::http_ws::http::MsgHandlerMgr http_msg_handler_mgr_;
};
}
}

#endif // DEMO_SERVER_HTTP_WS_LOGICS_LOGIC_H_
