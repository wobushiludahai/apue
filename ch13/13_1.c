/*
 * @Author: land sea
 * @Date: 2020-01-29 18:06:28
 * @LastEditTime : 2020-01-29 18:24:58
 * @LastEditors  : Please set LastEditors
 * @Description: daemonize函数
 * @FilePath: /apue/ch13/13_1.c
 */
#include "apue.h"
#include <syslog.h>
#include <fcntl.h>
#include <sys/resource.h>

void daemonize(const char *cmd)
{
    int i, fd0, fd1, fd2;
    pid_t pid;
    struct rlimit rl;
    struct sigaction sa;

    umask(0);

    if(getrlimit(RLIMIT_NOFILE, &rl) < 0)
    {
        err_quit("%s: can't get file limit", cmd);
    }

    if((pid = fork()) < 0)
    {
        err_quit("%s: can't fork", cmd);
    }
    else if(pid != 0)
    {
        exit(0);    //父进程
    }
    setsid();
    
    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if(sigaction(SIGHUP, &sa, NULL) < 0)
    {
        err_quit("%s: can't ignore SIGHUP", cmd);
    }

    if((pid = fork()) < 0)
    {
        err_quit("%s: can't fork", cmd);
    }
    else if(pid != 0)
    {
        exit(0);
    }

    if(chdir("/") < 0)      //改变目录
    {
        err_quit("%s: can't change directory to /", cmd);
    }

    //关闭所有文件描述符
    if(rl.rlim_max == RLIM_INFINITY)
    {
        rl.rlim_max = 1024;
    }
    for(i = 0; i < rl.rlim_max; i++)
    {
        close(i);
    }

    fd0 = open("/dev/null", O_RDWR);
    fd1 = dup(0);
    fd2 = dup(0);

    //初始化ｌｏｇ文件
    openlog(cmd, LOG_CONS, LOG_DAEMON);
    if(fd0 != 0 || fd1 != 1 || fd2 != 2)
    {
        syslog(LOG_ERR, "unexpected file descriptors %d %d %d", fd0, fd1, fd2);
        exit(1);
    }
}