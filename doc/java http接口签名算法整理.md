接口提供方维护一个app_id和app_key(密钥)。

## 接口说明
### 请求参数及格式
| column | column |
|--------|--------|
|  app_id      |        |
|  timestamp      |        |

### 回复字段及格式

std::ostringstream oss_md5_base;
    oss_md5_base << "app_id=" << global_logic_->GetGlobalConfMgr()->GetUserCenterAppID() << "&timestamp="
        << (now * 1000) << "&token=" << it_token->second << "&uid=" << it_uid->second
        << global_logic_->GetGlobalConfMgr()->GetUserCenterAppKey();
    std::string md5_base = oss_md5_base.str();
    
    
    
     // 计算签名
    char md5[MD5_STR_LEN + 1] = "";
    int md5_len = CalcMD5(md5, sizeof(md5), (const unsigned char*) md5_base.c_str(), md5_base.length());
    if (md5_len <= 0)
    {
        LOG_ERROR("failed to calc md5 of str");
        return;
    }

    LOG_TRACE("md5: " << md5);

    for (int i = 0; i < md5_len; ++i)
    {
        md5[i] = (char) tolower(md5[i]);
    }

    std::ostringstream oss_post;
    oss_post << "app_id=" << global_logic_->GetGlobalConfMgr()->GetUserCenterAppID() << "&timestamp="
        << (now * 1000) << "&token=" << it_token->second << "&uid=" << it_uid->second << "&sign=" << md5;
