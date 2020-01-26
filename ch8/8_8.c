/*
 * @Author: land sea
 * @Date: 2020-01-26 11:56:06
 * @LastEditTime : 2020-01-26 12:01:57
 * @LastEditors  : Please set LastEditors
 * @Description: 僵死进程
 * @FilePath: /apue/ch8/8_8.c
 */
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    pid_t pid;

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        if((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if(pid > 0)
        {
            exit(0);
        }

        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    if(waitpid(pid, NULL, 0) != pid)
    {
        err_sys("waitpid error");
    }

    exit(0);
}