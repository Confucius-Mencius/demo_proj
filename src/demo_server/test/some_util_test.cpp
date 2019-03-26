#include "some_util_test.h"
#include "some_util.h"

SomeUtilTest::SomeUtilTest()
{
}

SomeUtilTest::~SomeUtilTest()
{
}

void SomeUtilTest::SetUpTestCase()
{
}

void SomeUtilTest::TearDownTestCase()
{
}

void SomeUtilTest::SetUp()
{
}

void SomeUtilTest::TearDown()
{
}

void SomeUtilTest::Test001()
{
    SomeUtil some_util;
    EXPECT_EQ(0, some_util.Func());
}

ADD_TEST_F(SomeUtilTest, Test001);
