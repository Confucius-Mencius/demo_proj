#ifndef DEMO_SERVER_BURDEN_LOCAL_LOGIC_LOCAL_LOGIC_H_
#define DEMO_SERVER_BURDEN_LOCAL_LOGIC_LOCAL_LOGIC_H_

#include "burden_local_logic_interface.h"

namespace burden
{
class LocalLogic : public TheLocalLogicInterface
{
public:
    LocalLogic();
    virtual ~LocalLogic();

    ///////////////////////// ModuleInterface /////////////////////////
    const char* GetVersion() const override;
    const char* GetLastErrMsg() const override;
    void Release() override;
    int Initialize(const void* ctx) override;
    void Finalize() override;
    int Activate() override;
    void Freeze() override;

    ///////////////////////// burden::LogicInterface /////////////////////////
    void OnStop() override;

    ///////////////////////// burden::LocalLogicInterface /////////////////////////

    ///////////////////////// burden::TheLocalLogicInterface /////////////////////////
};
}

#endif // DEMO_SERVER_BURDEN_LOCAL_LOGIC_LOCAL_LOGIC_H_
