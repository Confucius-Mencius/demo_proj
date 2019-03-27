#ifndef DEMO_SERVER_UTIL_INC_THE_GLOBAL_LOGIC_INTERFACE_H_
#define DEMO_SERVER_UTIL_INC_THE_GLOBAL_LOGIC_INTERFACE_H_

#include <string>
#include "global_logic_interface.h"
#include "util.h"

// 注意：global logic是供所有线程访问的逻辑，一般需要加锁

// 为了配置的集中管理和reload的方便，在这里定义一个全局的DemoConfMgrInterface，管理用到的所有配置项

namespace global
{
class ConfMgrInterface
{
public:
    virtual ~ConfMgrInterface()
    {
    }

    virtual bool TestMode() = 0;
    virtual std::string GetZKHost() = 0;
    virtual int GetZKTimeout() = 0;
    virtual int GetZKLogLevel() = 0;
    virtual std::string GetZKLogFilePath() = 0;
    virtual std::string GetZKUserPass() = 0;
};

class SomeModuleInterface
{
public:
    virtual ~SomeModuleInterface()
    {
    }

    virtual int Func(const char* arg) = 0;
};

class TheLogicInterface : public LogicInterface
{
public:
    virtual ~TheLogicInterface()
    {
    }

    virtual ConfMgrInterface* GetConfMgr() const = 0;
    virtual SomeModuleInterface* GetSomeModule() const = 0;
};
}

#endif // DEMO_SERVER_UTIL_INC_THE_GLOBAL_LOGIC_INTERFACE_H_
