#include "err_code.h"
#include <map>
#include "num_util.h"
#include "singleton.h"

static struct std::pair<int, std::pair<const char*, const char*>> err_msg_ctx_list[] =
{
    // 用脚本自动生成
    { ERR_OK, { "success", "成功" }},
    { ERR_INVALID_PARAM, { "invalid param", "参数非法" }},
    { ERR_SYS_ERROR, { "system error", "系统错误" }},
};

class ErrMsgCtxCenter
{
public:
    ErrMsgCtxCenter()
    {
        for (int i = 0; i < COUNT_OF(err_msg_ctx_list); ++i)
        {
            err_msg_map_[err_msg_ctx_list[i].first] = err_msg_ctx_list[i].second;
        }
    }

    ~ErrMsgCtxCenter()
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
    typedef std::map<int, std::pair<const char*, const char*>> ErrMsgHashMap;
    ErrMsgHashMap err_msg_map_;
};

const char* ErrMsgEn(int err_code)
{
    return Singleton<ErrMsgCtxCenter>::Instance()->ErrMsg(err_code).first;
}

const char* ErrMsgZh(int err_code)
{
    return Singleton<ErrMsgCtxCenter>::Instance()->ErrMsg(err_code).second;
}
