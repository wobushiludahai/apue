/*
 * @Author: land sea
 * @Date: 2020-01-27 16:48:37
 * @LastEditTime : 2020-01-27 16:56:33
 * @LastEditors  : Please set LastEditors
 * @Description: alarm函数用于设置阻塞操作的时间上限
 * @FilePath: /apue/ch10/10_10.c
 */
#include "apue.h"

static void sig_alrm(int);

int main(void)
{
    int n;
    char line[MAXLINE];

    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
    {
        err_sys("signal(SIGALRM) error");
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
    //nothing to do, just return
}