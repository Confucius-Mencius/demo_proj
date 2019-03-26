#ifndef COMMON_UTIL_INC_ERR_CODE_H_
#define COMMON_UTIL_INC_ERR_CODE_H_

const char* ErrMsgEn(int err_code);
const char* ErrMsgZh(int err_code);

// 用脚本自动生成
#define ERR_OK                                   0      // 成功
#define ERR_INVALID_PARAM                        1      // 参数非法
#define ERR_SYS_ERROR                            2      // 系统错误

#endif // COMMON_UTIL_INC_ERR_CODE_H_
