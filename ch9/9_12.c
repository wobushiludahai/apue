/*
 * @Author: land sea
 * @Date: 2020-01-27 11:41:14
 * @LastEditTime : 2020-01-27 11:56:29
 * @LastEditors  : Please set LastEditors
 * @Description: 孤儿进程组示例
 * @FilePath: /apue/ch9/9_12.c
 */
#include "apue.h"
#include <errno.h>

static void sig_hup(int signo)
{
    printf("SIGHUP received, pid = %ld\n", (long)getpid());
}

static void pr_ids(char *name)
{
    printf("%s: pid = %ld, ppid = %ld, pgrp = %ld, tpgrp = %ld\n", name ,\
            (long)getpid(), (long)getppid(), (long)getpgrp(), (long)tcgetpgrp(STDIN_FILENO));
}

int main(void)
{
    char c;
    pid_t pid;

    pr_ids("parent");
    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid > 0)
    {
        sleep(5);
    }
    else
    {
        pr_ids("child");
        signal(SIGHUP, sig_hup);
        kill(getpid(), SIGTSTP);
        pr_ids("child");
        if(read(STDIN_FILENO, &c, 1) != 1)
        {
            printf("read error %d on controlling TTY\n", errno);
        }

        exit(0);
    }
}