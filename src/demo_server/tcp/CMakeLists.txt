###############################################################################
# author: BrentHuang (guang11cheng@qq.com)
###############################################################################

# 定义USE_BUFFEREVENT宏，使用buffer event方式。注释掉则不使用buffer event方式。
add_definitions(-DUSE_BUFFEREVENT)

###############################################################################
# sub dir
add_subdirectory(common_logic)
add_subdirectory(logics)
