#ifndef DEMO_SERVER_HTTP_LOGICS_LOGIC_H_
#define DEMO_SERVER_HTTP_LOGICS_LOGIC_H_

#include <string>
#include "http_logic_interface.h"
#include "msg_handler_mgr.h"

namespace http
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

    ///////////////////////// http::LogicInterface /////////////////////////
    void OnStop() override;
    void OnReload() override;

private:
    MsgHandlerMgr msg_handler_mgr_;
};
}

#endif // DEMO_SERVER_HTTP_LOGICS_LOGIC_H_
