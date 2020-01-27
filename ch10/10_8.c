/*
 * @Author: land sea
 * @Date: 2020-01-27 16:23:27
 * @LastEditTime : 2020-01-27 16:30:27
 * @LastEditors  : Please set LastEditors
 * @Description: 解决10_7.c中的竞争条件问题
 * @FilePath: /apue/ch10/10_8.c
 */
#include <setjmp.h>
#include <signal.h>
#include <unistd.h>

static jmp_buf env_alrm;

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}

unsigned int sleep2(unsigned int seconds)
{
    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    {
        return (seconds);
    }

    if(setjmp(env_alrm) == 0)
    {
        alarm(seconds);
        pause();
    }

    return(alarm(0));
}