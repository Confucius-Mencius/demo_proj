#include "some_common_util.h"
#include "log_util.h"

SomeCommonUtil::SomeCommonUtil()
{
}

SomeCommonUtil::~SomeCommonUtil()
{
}

int SomeCommonUtil::Func()
{
    LOG_TRACE("hello, world");
    return 0;
}
