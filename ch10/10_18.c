/*
 * @Author: land sea
 * @Date: 2020-01-27 19:28:53
 * @LastEditTime : 2020-01-27 19:39:22
 * @LastEditors  : Please set LastEditors
 * @Description: signal函数使用sigaction实现的方法
 * @FilePath: /apue/ch10/10_18.c
 */
#include "apue.h"

Sigfunc *signal(int signo, Sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if(signo == SIGALRM)
    {
        #ifdef SA_INTERRUPT
            act.sa_flags |= SA_INTERRUPT;
        #endif
    }
    else
    {
        act.sa_flags |= SA_RESTART;
    }

    if(sigaction(signo, &act, &oact) < 0)
    {
        return (SIG_ERR);
    }
    return (oact.sa_handler);
}