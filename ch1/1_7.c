/*
 * @Author: land sea
 * @Date: 2020-01-20 19:23:57
 * @LastEditTime : 2020-01-20 19:55:39
 * @LastEditors  : Please set LastEditors
 * @Description: 从标准输入读取命令，然后执行这些命令
 * @FilePath: /apue/ch1/1_7.c
 */
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    char buf[MAXLINE];
    pid_t pid;
    int status;

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