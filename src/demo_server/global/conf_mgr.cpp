#include "conf_mgr.h"

namespace global
{
ConfMgr::ConfMgr() : rwlock_()
{
}

ConfMgr::~ConfMgr()
{
}

int ConfMgr::Load()
{
    AUTO_THREAD_WLOCK(rwlock_);

    test_mode_ = false;
    zk_host_ = "";
    zk_timeout_ = 0;
    zk_log_level_ = 0;
    zk_log_file_path_ = "";
    zk_user_pass_ = "";

    if (LoadTestMode() != 0)
    {
        return -1;
    }

    if (LoadZKHost() != 0)
    {
        return -1;
    }

    if (LoadZKTimeout() != 0)
    {
        return -1;
    }

    if (LoadZKLogLevel() != 0)
    {
        return -1;
    }

    if (LoadZKLogFilePath() != 0)
    {
        return -1;
    }

    if (LoadZKUserPass() != 0)
    {
        return -1;
    }

    return 0;
}
}
