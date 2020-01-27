/*
 * @Author: land sea
 * @Date: 2020-01-27 19:44:27
 * @LastEditTime : 2020-01-27 19:49:33
 * @LastEditors  : Please set LastEditors
 * @Description: 去除重启动的signal函数实现
 * @FilePath: /apue/ch10/10_19.c
 */
#include "apue.h"

Sigfunc *signal_intr(int signo, Sigfunc *func)
{
    struct sigaction act, oact;

    act.sa_handler = func;
    sigemptyset(&act.sa_flags);
    act.sa_flags = 0;
    #ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
    #endif
    if(sigaction(signo, &act, &oact) < 0)
    {
        return SIG_ERR;
    }
    return (oact.sa_handler);
}