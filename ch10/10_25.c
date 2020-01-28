/*
 * @Author: land sea
 * @Date: 2020-01-27 22:10:54
 * @LastEditTime : 2020-01-28 09:19:43
 * @LastEditors  : Please set LastEditors
 * @Description: abort函数的一种实现
 * @FilePath: /apue/ch10/10_25.c
 */
#include <signal.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
#include "apue.h"

void abort(void)
{
    sigset_t mask;
    struct sigaction action;
    
    sigaction(SIGABRT, NULL, ＆action);
    if(action.sa_handler == SIG_IGN)
    {
        action.sa_handler = SIG_DFL;
        sigaction(SIGABRT, &action, NULL);
    }

    if(action.sa_handler == SIG_DFL)
    {
        fflush(NULL);
    }

    sigfillset(&mask);
    sigdelset(&mask, SIGABRT);
    sigprocmask(SIG_SETMASK, &mask, NULL);
    kill(getpid(), SIGABRT);

    fflush(NULL);
    action.sa_hanler = SIG_DFL;
    sigaction(SIGABRT, &action, NULL);
    sigprocmask(SIG_SETMASK, &mask, NULL);
    kill(getpid(), SIGABRT);
    exit(1);
}