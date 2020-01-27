/*
 * @Author: land sea
 * @Date: 2020-01-27 16:59:31
 * @LastEditTime : 2020-01-27 17:11:19
 * @LastEditors  : Please set LastEditors
 * @Description: 使用longjmp改善10_10.c中的竞争问题
 * @FilePath: /apue/ch10/10_11.c
 */
#include "apue.h"
#include <setjmp.h>

static void sig_alrm(int);
static jmp_buf env_alrm;

int main(void)
{
    int n;
    char line[MAXLINE];

    if(signal(SIGALRM,sig_alrm) == SIG_ERR)
    {
        err_sys("signal(SIGALRM) error");
    }

    if(setjmp(env_alrm) != 0)
    {
        err_quit("read timeout");
    }

    alarm(10);
    if((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
    {
        err_sys("read error");
    }
    alarm(0);
    
    write(STDOUT_FILENO, line, n);
    exit(0);
}

static void sig_alrm(int signo)
{
    longjmp(env_alrm, 1);
}