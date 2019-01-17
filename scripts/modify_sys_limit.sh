# 修改单个进程可以打开的最大文件描述符数
#----------------------------------------------------------------------
if ! grep /etc/security/limits.conf -rne '^[^#].*nofile'; then
    echo '修改单个进程可以打开的最大文件描述符数'
    sudo sed /etc/security/limits.conf -e '/End of file/i\
*                soft   nofile          655350\
*                hard   nofile          655350\
root             soft   nofile          655350\
root             hard   nofile          655350' -i
fi
#----------------------------------------------------------------------

#开启core dump
#----------------------------------------------------------------------
if ! grep /etc/security/limits.conf -rne '^[^#].*core'; then
    echo '开启core dump'
    sudo sed /etc/security/limits.conf -e '/End of file/i\
*                soft    core            unlimited\
*                hard    core            unlimited\
root             soft    core            unlimited\
root             hard    core            unlimited' -i
fi
#----------------------------------------------------------------------

#设置core dump文件格式
#----------------------------------------------------------------------
# if ! grep /etc/rc.local -rne core_pattern; then
#     echo '设置core dump文件格式'
#     echo "exit 0" >> /etc/rc.local
#     sudo sed /etc/rc.local -e'/^exit 0/iecho 1 > /proc/sys/kernel/core_uses_pid\necho core-%e-%p-%t > /proc/sys/kernel/core_pattern' -i
# fi
#----------------------------------------------------------------------

#设置fs.file-max、core dump文件格式和网络优化参数
#----------------------------------------------------------------------
if ! grep /etc/sysctl.conf -rne 'fs.file-max'; then
    echo '设置fs.file-max、core dump文件格式和网络优化参数'
    echo 'fs.file-max = 6553500
kernel.core_pattern=core-%e-%p-%t
kernel.core_uses_pid=0
net.ipv4.ip_local_port_range = 1024 65535
net.core.rmem_max=16777216
net.core.wmem_max=16777216
net.ipv4.tcp_rmem=4096 87380 16777216
net.ipv4.tcp_wmem=4096 65536 16777216
net.ipv4.tcp_fin_timeout = 10
net.ipv4.tcp_tw_recycle = 1
net.ipv4.tcp_timestamps = 0
net.ipv4.tcp_window_scaling = 0
net.ipv4.tcp_sack = 0
net.core.netdev_max_backlog = 30000
net.ipv4.tcp_no_metrics_save=1
net.core.somaxconn = 262144
net.ipv4.tcp_syncookies = 0
net.ipv4.tcp_max_orphans = 262144
net.ipv4.tcp_max_syn_backlog = 262144
net.ipv4.tcp_synack_retries = 2
net.ipv4.tcp_syn_retries = 2' | sudo tee /etc/sysctl.conf
fi
#----------------------------------------------------------------------
