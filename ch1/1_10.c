/*
 * @Author: land sea
 * @Date: 2020-01-20 19:23:57
 * @LastEditTime : 2020-01-20 21:26:12
 * @LastEditors  : Please set LastEditors
 * @Description: signal函数
 * @FilePath: /apue/ch1/1_7.c
 */
#include "apue.h"
#include <sys/wait.h>

static void sig_int(int);

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR)
    {
        err_sys("signal error");
    }

    printf("%%");
    while(fgets(buf, MAXLINE, stdin) != NULL)
    {
        if(buf[strlen(buf) - 1] == '\n')
        {
            buf[strlen(buf) - 1] = 0;    //替代换行符
        }

        if((pid = fork()) < 0)      //创建新进程
        {
            err_sys("fork error");
        }
        else if(pid == 0)   //子进程
        {
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute: %s", buf);
            exit(127);
        }

        if((pid = waitpid(pid, &status, 0)) < 0)    //等待进程返回
        {
            err_sys("waitpid error");
        }

        printf("%%");
    }
    exit(0);
}

void sig_int(int signo)
{
    printf("interrupt\n%% ");
}