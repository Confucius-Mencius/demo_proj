#ifndef DEMO_SERVER_WORK_COMMON_LOGIC_COMMON_LOGIC_H_
#define DEMO_SERVER_WORK_COMMON_LOGIC_COMMON_LOGIC_H_

#include "work_common_logic_interface.h"

namespace work
{
class CommonLogic : public TheCommonLogicInterface
{
public:
    CommonLogic();
    virtual ~CommonLogic();

    ///////////////////////// ModuleInterface /////////////////////////
    const char* GetVersion() const override;
    const char* GetLastErrMsg() const override;
    void Release() override;
    int Initialize(const void* ctx) override;
    void Finalize() override;
    int Activate() override;
    void Freeze() override;

    ///////////////////////// LogicInterface /////////////////////////
    void OnStop() override;

    ///////////////////////// CommonLogicInterface /////////////////////////

    ///////////////////////// TheCommonLogicInterface /////////////////////////
};
}

#endif // DEMO_SERVER_WORK_COMMON_LOGIC_COMMON_LOGIC_H_
