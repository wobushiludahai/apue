/*
 * @Author: land sea
 * @Date: 2020-01-27 21:41:35
 * @LastEditTime : 2020-01-27 22:05:17
 * @LastEditors  : Please set LastEditors
 * @Description: TELLWAIT/TELL_PARENT/TELL_CHILD/WAIT_PARENT/WAIT_CHILD
 * @FilePath: /apue/ch10/10_24.c
 */
#include "apue.h"

static volatile sig_atomic_t sigflag;
static sigset_t newmask, oldmask, zeromask;

static void sig_usr(int signo)
{
    sigflag = 1;
}

void TELL_WAIT(void)
{
    if(signal(SIGUSR1, sig_usr) == SIG_ERR)
    {
        err_sys("signal(SIGUSR1) error");
    }
    
    if(signal(SIGUSR2, sig_usr) == SIG_ERR)
    {
        err_sys("signal(SIGUSER2) error");
    }

    sigemptyset(&zeromask);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGUSR1);
    sigaddset(&newmask, SIGUSR2);

    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0)
    {
        err_sys("SIG_BLOCK error");
    }
}

void TELL_PARENT(pid_t pid)
{
    kill(pid, SIGUSR2);
}

void WAIT_PARENT(void)
{
    while(sigflag == 0)
    {
        sigsuspend(&zeromask);
    }
    sigflag = 0;

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
        err_sys("SIG_SETMASK error");
    }
}

void TELL_CHILD(pid_t pid)
{
    kill(pid, SIGUSR1);
}

void WAIT_CHILD(void)
{
    while(sigflag == 0)
    {
        sigsuspend(&zeromask);
    }
    sigflag = 0;

    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0)
    {
        err_sys("SIG_SETMASK error");
    }
}