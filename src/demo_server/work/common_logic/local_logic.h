#ifndef DEMO_SERVER_WORK_LOCAL_LOGIC_LOCAL_LOGIC_H_
#define DEMO_SERVER_WORK_LOCAL_LOGIC_LOCAL_LOGIC_H_

#include "work_local_logic_interface.h"

namespace work
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

    ///////////////////////// work::LogicInterface /////////////////////////
    void OnStop() override;

    ///////////////////////// work::LocalLogicInterface /////////////////////////

    ///////////////////////// work::TheLocalLogicInterface /////////////////////////
};
}

#endif // DEMO_SERVER_WORK_LOCAL_LOGIC_LOCAL_LOGIC_H_
