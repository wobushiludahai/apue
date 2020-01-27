/*
 * @Author: land sea
 * @Date: 2020-01-27 13:52:07
 * @LastEditTime : 2020-01-27 14:00:41
 * @LastEditors  : Please set LastEditors
 * @Description: 简单信号处理程序
 * @FilePath: /apue/ch10/10_2.c
 */
#include "apue.h"

static void sig_usr(int);

int main(void)
{
    if(signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        err_sys("can't catch SIGUSR1");
    }

    if(signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        err_sys("can't catch SIGUSR2");
    }

    for(;;)
    {
        pause();
    }
}

static void sig_usr(int signo)
{
    if(signo == SIGUSR1)
    {
        printf("received SIGUSR1\n");
    }
    else if(signo == SIGUSR2)
    {
        printf("received SIGUSR2\n");
    }
    else
    {
        err_dump("received signal %d\n", signo);
    }
}