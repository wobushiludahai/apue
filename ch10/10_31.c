/*
 * @Author: land sea
 * @Date: 2020-01-28 10:57:47
 * @LastEditTime : 2020-01-28 11:07:34
 * @LastEditors  : Please set LastEditors
 * @Description: 将标准输入复制到标准输出
 * @FilePath: /apue/ch10/10_31.c
 */
#include "apue.h"

#define BUFFSIZE 1024

static void sig_tstp(int signo)
{
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGTSTP);
    sigprocmask(SIG_UNBLOCK, &mask, NULL);

    signal(SIGTSTP, SIG_DFL);
    kill(getpid(), SIGTSTP);
    signal(SIGTSTP, sig_tstp);
}

int main(void)
{
    int n;
    char buf[BUFFSIZE];

    if(signal(SIGTSTP, SIG_IGN) == SIG_DFL)
    {
        signal(SIGTSTP, sig_tstp);
    }

    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            err_sys("write error");
        }
    }

    if(n < 0)
    {
        err_sys("read error");
    }

    exit(0);
}