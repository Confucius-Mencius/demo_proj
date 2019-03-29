#ifndef DEMO_SERVER_GLOBAL_CONF_MGR_H_
#define DEMO_SERVER_GLOBAL_CONF_MGR_H_

#include <string>
#include <vector>
#include "conf_center_interface.h"
#include "conf_mgr_interface.h"
#include "conf_xpath.h"
#include "log_util.h"
#include "the_global_logic_interface.h"
#include "thread_lock.h"

namespace global
{
class ConfMgr : public base::ConfMgrInterface, public ConfMgrInterface
{
public:
    ConfMgr();
    virtual ~ConfMgr();

private:
    ///////////////////////// base::ConfMgrInterface /////////////////////////
    int Load() override;

public:
    ///////////////////////// ConfMgrInterface /////////////////////////
    bool TestMode() override
    {
        AUTO_THREAD_RLOCK(rwlock_);
        return test_mode_;
    }

    std::string GetZKHost() override
    {
        AUTO_THREAD_RLOCK(rwlock_);
        return zk_host_;
    }

    int GetZKTimeout() override
    {
        AUTO_THREAD_RLOCK(rwlock_);
        return zk_timeout_;
    }

    int GetZKLogLevel() override
    {
        AUTO_THREAD_RLOCK(rwlock_);
        return zk_log_level_;
    }

    std::string GetZKLogFilePath() override
    {
        AUTO_THREAD_RLOCK(rwlock_);
        return zk_log_file_path_;
    }

    std::string GetZKUserPass() override
    {
        AUTO_THREAD_RLOCK(rwlock_);
        return zk_user_pass_;
    }

private:
    int LoadTestMode()
    {
        int test_mode = 0;
        if (conf_center_->GetConf(test_mode, TEST_MODE_XPATH, true, 0) != 0)
        {
            LOG_ERROR("failed to get " << TEST_MODE_XPATH << ": " << conf_center_->GetLastErrMsg());
            return -1;
        }
        test_mode_ = (test_mode != 0);
        return 0;
    }

    int LoadZKHost()
    {
        char* zk_host = nullptr;
        if (conf_center_->GetConf(&zk_host, ZK_HOST_XPATH, false) != 0)
        {
            LOG_ERROR("failed to get " << ZK_HOST_XPATH << ": " << conf_center_->GetLastErrMsg());
            conf_center_->ReleaseConf(&zk_host);
            return -1;
        }
        zk_host_ = zk_host;
        conf_center_->ReleaseConf(&zk_host);
        return 0;
    }

    int LoadZKTimeout()
    {
        if (conf_center_->GetConf(zk_timeout_, ZK_TIMEOUT_XPATH, false) != 0)
        {
            LOG_ERROR("failed to get " << ZK_TIMEOUT_XPATH << ": " << conf_center_->GetLastErrMsg());
            return -1;
        }
        return 0;
    }

    int LoadZKLogLevel()
    {
        if (conf_center_->GetConf(zk_log_level_, ZK_LOG_LEVEL_XPATH, false) != 0)
        {
            LOG_ERROR("failed to get " << ZK_LOG_LEVEL_XPATH << ": " << conf_center_->GetLastErrMsg());
            return -1;
        }
        return 0;
    }

    int LoadZKLogFilePath()
    {
        char* zk_log_file_path = nullptr;
        if (conf_center_->GetConf(&zk_log_file_path, ZK_LOG_FILE_PATH_XPATH, false) != 0)
        {
            LOG_ERROR("failed to get " << ZK_LOG_FILE_PATH_XPATH << ": " << conf_center_->GetLastErrMsg());
            conf_center_->ReleaseConf(&zk_log_file_path);
            return -1;
        }
        zk_log_file_path_ = zk_log_file_path;
        conf_center_->ReleaseConf(&zk_log_file_path);
        return 0;
    }

    int LoadZKUserPass()
    {
        char* zk_user_pass = nullptr;
        if (conf_center_->GetConf(&zk_user_pass, ZK_USER_PASS_XPATH, false) != 0)
        {
            LOG_ERROR("failed to get " << ZK_USER_PASS_XPATH << ": " << conf_center_->GetLastErrMsg());
            conf_center_->ReleaseConf(&zk_user_pass);
            return -1;
        }
        zk_user_pass_ = zk_user_pass;
        conf_center_->ReleaseConf(&zk_user_pass);
        return 0;
    }

private:
    ThreadRWLock rwlock_;
    bool test_mode_;
    std::string zk_host_;
    int zk_timeout_;
    int zk_log_level_;
    std::string zk_log_file_path_;
    std::string zk_user_pass_;
};
}

#endif // DEMO_SERVER_GLOBAL_CONF_MGR_H_
