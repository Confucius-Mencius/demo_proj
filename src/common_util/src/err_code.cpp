#include "err_code.h"
#include "hash_container.h"
#include "num_util.h"
#include "singleton.h"

static struct std::pair<int, std::pair<const char*, const char*>> ERR_MSG_LIST[] =
{
    // 用脚本自动生成
    { ERR_OK, { "success", "成功" }},
    { ERR_INVALID_PARAM, { "invalid param", "参数非法" }},
    { ERR_SYS_ERROR, { "system error", "系统错误" }},
};

class ErrMsgMgr
{
public:
    ErrMsgMgr()
    {
        for (int i = 0; i < COUNT_OF(ERR_MSG_LIST); ++i)
        {
            err_msg_map_[ERR_MSG_LIST[i].first] = ERR_MSG_LIST[i].second;
        }
    }

    ~ErrMsgMgr()
    {
        err_msg_map_.clear();
    }

    std::pair<const char*, const char*> ErrMsg(int err_code) const
    {
        ErrMsgHashMap::const_iterator it = err_msg_map_.find(err_code);
        if (it != err_msg_map_.end())
        {
            return it->second;
        }

        return std::pair<const char*, const char*>(NULL, NULL);
    }

private:
    typedef __hash_map<int, std::pair<const char*, const char*>> ErrMsgHashMap;
    ErrMsgHashMap err_msg_map_;
};

const char* ErrMsgEn(int err_code)
{
    return Singleton<ErrMsgMgr>::Instance()->ErrMsg(err_code).first;
}

const char* ErrMsgZh(int err_code)
{
    return Singleton<ErrMsgMgr>::Instance()->ErrMsg(err_code).second;
}
