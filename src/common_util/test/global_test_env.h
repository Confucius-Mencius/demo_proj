#ifndef COMMON_UTIL_TEST_GLOBAL_TEST_ENV_H_
#define COMMON_UTIL_TEST_GLOBAL_TEST_ENV_H_

#include <gmock/gmock.h>
#include "console_log_engine.h"

// 全局测试环境
class GlobalTestEnv : public testing::Environment
{
public:
    GlobalTestEnv();
    virtual ~GlobalTestEnv();

    // 该函数在所有的测试用例组之前执行
    virtual void SetUp();

    // 该函数在所有的测试用例组之后执行
    virtual void TearDown();

private:
    ConsoleLogEngine console_log_engine_;
};

extern GlobalTestEnv* g_global_test_env;

#endif // COMMON_UTIL_TEST_GLOBAL_TEST_ENV_H_
