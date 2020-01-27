/*
 * @Author: your name
 * @Date: 2020-01-27 17:55:53
 * @LastEditTime : 2020-01-27 18:06:04
 * @LastEditors  : Please set LastEditors
 * @Description: 打印调用进程信号屏蔽字中的信号名
 * @FilePath: /apue/ch10/10_14.c
 */
#include "apue.h"
#include <errno.h>

void pr_mask(const char *str)
{
    sigset_t sigset;
    int errno_save;

    errno_save = errno;
    if(sigprocmask(0, NULL, &sigset) < 0)
    {
        err_ret("sigprocmask error");
    }
    else
    {
        printf("%s", str);
        if(sigismember(&sigset, SIGINT))
        {
            printf(" SIGNET");
        }
        
        if(sigismember(&sigset, SIGQUIT))
        {
            printf(" SIGQUIT");
        }

        if(sigismember(&sigset, SIGUSR1))
        {
            printf(" SIGUSR1");
        }

        if(sigismember(&sigset, SIGALRM))
        {
            printf(" SIGALRM");
        }

        printf("\n");
    }

    errno = errno_save;
}