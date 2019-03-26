#ifndef COMMON_UTIL_TEST_SOME_COMMON_UTIL_TEST_H_
#define COMMON_UTIL_TEST_SOME_COMMON_UTIL_TEST_H_

#include "test_util.h"

class SomeCommonUtilTest : public GTest
{
public:
    SomeCommonUtilTest();
    virtual ~SomeCommonUtilTest();

    static void SetUpTestCase();
    static void TearDownTestCase();

    virtual void SetUp();
    virtual void TearDown();

    void Test001();

private:

};

#endif // COMMON_UTIL_TEST_SOME_COMMON_UTIL_TEST_H_
