#include "some_common_util_test.h"
#include "some_common_util.h"

SomeCommonUtilTest::SomeCommonUtilTest()
{

}

SomeCommonUtilTest::~SomeCommonUtilTest()
{

}

void SomeCommonUtilTest::SetUpTestCase()
{

}

void SomeCommonUtilTest::TearDownTestCase()
{

}

void SomeCommonUtilTest::SetUp()
{
}

void SomeCommonUtilTest::TearDown()
{
}

void SomeCommonUtilTest::Test001()
{
    SomeCommonUtil some_common_util;
    EXPECT_EQ(0, some_common_util.Func());
}

ADD_TEST_F(SomeCommonUtilTest, Test001);
