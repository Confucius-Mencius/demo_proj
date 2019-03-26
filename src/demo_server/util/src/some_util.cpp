#include "some_util.h"
#include "log_util.h"

SomeUtil::SomeUtil()
{

}

SomeUtil::~SomeUtil()
{

}

int SomeUtil::Func()
{
    LOG_TRACE("hello, world");
    return 0;
}
