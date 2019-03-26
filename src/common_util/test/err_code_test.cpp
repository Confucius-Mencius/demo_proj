#include "err_code_test.h"
#include "err_code.h"

ErrCodeTest::ErrCodeTest()
{
}

ErrCodeTest::~ErrCodeTest()
{
}

void ErrCodeTest::Test001()
{
    const char* err_msg = ErrMsgEn(ERR_OK);
    EXPECT_STRCASEEQ("success", err_msg);

    err_msg = ErrMsgZh(ERR_OK);
    EXPECT_STRCASEEQ("成功", err_msg);

    err_msg = ErrMsgEn(ERR_INVALID_PARAM);
    EXPECT_STRCASEEQ("invalid param", err_msg);

    err_msg = ErrMsgZh(ERR_INVALID_PARAM);
    EXPECT_STRCASEEQ("参数非法", err_msg);

    err_msg = ErrMsgEn(ERR_SYS_ERROR);
    EXPECT_STRCASEEQ("system error", err_msg);

    err_msg = ErrMsgZh(ERR_SYS_ERROR);
    EXPECT_STRCASEEQ("系统错误", err_msg);
}

ADD_TEST_F(ErrCodeTest, Test001);
