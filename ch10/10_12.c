/*
 * @Author: land sea
 * @Date: 2020-01-27 17:28:52
 * @LastEditTime : 2020-01-27 17:42:01
 * @LastEditors  : Please set LastEditors
 * @Description: sigaddset/sigdelset/sigismember函数
 * @FilePath: /apue/ch10/10_12.c
 */
#include <signal.h>
#include <errno.h>

#define SIGBAD(signo) ((signo) <= 0 || (signo) >= NSIG)

int sigaddset(sigset_t *set, int signo)
{
    if(SIGBAD(signo))
    {
        errno = EINVAL;
        return (-1);
    }

    *set|= １<<(signo - 1);
    return(0);
}

int signdelset(sigset_t *set, int signo)
{
    if(SIGBAD(signo))
    {
        errno = EINVAL;
        return (-1);
    }
    *set &= ~(1<<(signo - 1));
    return (0);
}

int sigismember(const sigset_t *set, int signo)
{
    if(SIGBAD(signo))
    {
        errno = EINVAL;
        return (-1);
    }
    return((*set & (1 << (signo - 1))) != 0);
}