#include "some_test.h"

SomeTest::SomeTest()
{

}

SomeTest::~SomeTest()
{

}

void SomeTest::SetUpTestCase()
{

}

void SomeTest::TearDownTestCase()
{

}

void SomeTest::SetUp()
{
    Test::SetUp();
}

void SomeTest::TearDown()
{
    Test::TearDown();
}

void SomeTest::Test001()
{
    int a = 0;
    EXPECT_EQ(0, a);
    ASSERT_EQ(0, a);
}

ADD_TEST_F(SomeTest, Test001);
