/*
 * @Author: land sea
 * @Date: 2020-01-26 11:16:53
 * @LastEditTime : 2020-01-26 11:44:06
 * @LastEditors  : Please set LastEditors
 * @Description: 进程终止状态打印
 * @FilePath: /apue/ch8/8_6.c
 */
#include "apue.h"
#include <sys/wait.h>

void pr_exit(int status)
{
    if(WIFEXITED(status))
    {
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    }
    else if(WIFSIGNALED(status))
    {
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status), \
            "(core file generated)");
    }
    else if(WIFSTOPPED(status))
    {
        printf("child stopped. signal number = %d\n", WSTOPSIG(status));
    }
}

int main(void)
{
    pid_t pid;
    int status;

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        exit(7);
    }

    if(wait(&status) != pid)
    {
        err_sys("wait error");
    }
    pr_exit(status);

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        abort();
    }

    if(wait(&status) != pid)
    {
        err_sys("wait error");
    }
    pr_exit(status);

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        status /= 0;
    }

    if(wait(&status) != pid)
    {
        err_sys("wait error");
    }
    pr_exit(status);

    exit(0);
}