/*
 * @Author: land sea
 * @Date: 2020-01-27 16:15:03
 * @LastEditTime : 2020-01-27 16:23:07
 * @LastEditors  : Please set LastEditors
 * @Description: alarm/pause函数实现不太完善的sleep p269
 * @FilePath: /apue/ch10/10_7.c
 */
#include <signal.h>
#include <unistd.h>

static void sig_alrm(int signo)
{
    //do something
}

unsigned int sleep1(unsigned int seconds)
{
    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    {
        return (seconds);
    }

    alarm(seconds);
    pause();
    return(alarm(0));
}