/*
 * @Author: land sea
 * @Date: 2020-01-26 19:47:13
 * @LastEditTime : 2020-01-26 20:04:01
 * @LastEditors  : Please set LastEditors
 * @Description: system函数的一种实现
 * @FilePath: /apue/ch8/8_22.c
 */
#include "apue.h"
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>

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

int system(const char *cmdstring)
{
    pid_t pid;
    int status;

    if(cmdstring == NULL)
    {
        return (1);
    }

    if((pid = fork()) < 0)
    {
        status = -1;
    }
    else if(pid == 0)
    {
        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }
    else
    {
        while(waitpid(pid, &status, 0) < 0)
        {
            if(errno != EINTR)
            {
                status = -1;
                break;
            }
        }
    }

    return (status);
}

int main(void)
{
    int status;

    if((status = system("date")) < 0)
    {
        err_sys("system() error");
    }

    pr_exit(status);

    if((status = system("nosuchcommand")) < 0)
    {
        err_sys("system() error");
    }

    pr_exit(status);

    if((status = system("who; exit 44")) < 0)
    {
        err_sys("system() error");
    }

    pr_exit(status);

    exit(0);
}