#ifndef DEMO_SERVER_TEST_SOME_TEST_H_
#define DEMO_SERVER_TEST_SOME_TEST_H_

#include "test_util.h"

class SomeTest : public GTest
{
public:
    SomeTest();
    virtual ~SomeTest();

    static void SetUpTestCase();
    static void TearDownTestCase();

    virtual void SetUp();
    virtual void TearDown();

    void Test001();

private:

};

#endif // DEMO_SERVER_TEST_SOME_TEST_H_
