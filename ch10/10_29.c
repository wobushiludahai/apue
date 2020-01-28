/*
 * @Author: land sea
 * @Date: 2020-01-28 10:28:34
 * @LastEditTime : 2020-01-28 10:40:44
 * @LastEditors  : Please set LastEditors
 * @Description: sleep函数实现
 * @FilePath: /apue/ch10/10_29.c
 */
#include "apue.h"

static void sig_alrm(int signo)
{
    //nothing to do
}

unsigned int sleep(unsigned int seconds)
{
    struct sigaction newact, oldact;
    sigset_t newmask, oldmask, suspmask;
    unsigned int unslept;

    newact.sa_handler = sig_alrm;
    sigemptyset(&newact.sa_mask);
    newact.sa_flags = 0;
    sigaction(SIGALRM, &newact, &oldact);

    sigemptyset(&newmask);
    sigaddset(&newmask, SIGALRM);
    sigprocmask(SIG_BLOCK, &newmask, &oldmask);

    alarm(seconds);
    suspmask = oldmask;
    
    sigdelset(&suspmask, SIGALRM);
    sigsuspend(&suspmask);

    unslept = alarm(0);

    sigaction(SIGALRM, &oldact, NULL);

    sigprocmask(SIG_SETMASK, &oldmask, NULL);
    return(unslept);
}