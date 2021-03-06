/*
 * @Author: land sea
 * @Date: 2020-01-27 19:55:54
 * @LastEditTime : 2020-01-27 20:56:56
 * @LastEditors  : Please set LastEditors
 * @Description: sigsetjmp/siglongjmp函数示例
 * @FilePath: /apue/ch10/10_20.c
 */
#include "apue.h"
#include <setjmp.h>
#include <time.h>
#include <errno.h>
#include <signal.h>

static void sig_usrl(int);
static void sig_alrm(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

// #define SIGBAD(signo) ((signo) <= 0 || (signo) >= NSIG)

// int sigismember(const sigset_t *set, int signo)
// {
//     if(SIGBAD(signo))
//     {
//         errno = EINVAL;
//         return (-1);
//     }
//     return((*set & (1 << (signo - 1))) != 0);
// }

// void pr_mask(const char *str)
// {
//     sigset_t sigset;
//     int errno_save;

//     errno_save = errno;
//     if(sigprocmask(0, NULL, &sigset) < 0)
//     {
//         err_ret("sigprocmask error");
//     }
//     else
//     {
//         printf("%s", str);
//         if(sigismember(&sigset, SIGINT))
//         {
//             printf(" SIGNET");
//         }
        
//         if(sigismember(&sigset, SIGQUIT))
//         {
//             printf(" SIGQUIT");
//         }

//         if(sigismember(&sigset, SIGUSR1))
//         {
//             printf(" SIGUSR1");
//         }

//         if(sigismember(&sigset, SIGALRM))
//         {
//             printf(" SIGALRM");
//         }

//         printf("\n");
//     }

//     errno = errno_save;
// }

int main(void)
{
    if(signal(SIGUSR1, sig_usrl) == SIG_ERR)
    {
        err_sys("signal(SIGUSR1) error");
    }

    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    {
        err_sys("signal(SIGALRM) error");
    }

    pr_mask("starting main: ");
    
    if(sigsetjmp(jmpbuf, 1))
    {
        pr_mask("ending main: ");
        exit(0);
    }
    canjump = 1;
    for(;;)
    {
        pause();
    }   
}

static void sig_usrl(int signo)
{
    time_t starttime;
    
    if(canjump == 0)
    {
        return;
    }

    pr_mask("starting sig_usrl: ");

    alarm(3);
    starttime = time(NULL);
    for(;;)
    {
        if(time(NULL) > starttime + 5)
        {
            break;
        }
    }
    pr_mask("finish sig_usrl: ");

    canjump = 0;
    siglongjmp(jmpbuf, 1);
}

static void sig_alrm(int signo)
{
    pr_mask("in sig_alrm: ");
}