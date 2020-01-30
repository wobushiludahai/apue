/*
 * @Author: land sea
 * @Date: 2020-01-30 10:07:05
 * @LastEditTime : 2020-01-30 10:13:52
 * @LastEditors  : Please set LastEditors
 * @Description: 创建管道，并使父进程向子进程传送数据
 * @FilePath: /apue/ch15/15_5.c
 */
#include "apue.h"

int main(void)
{
    int n;
    int fd[2];
    pid_t pid;
    char line[MAXLINE];

    if(pipe(fd) < 0)
    {
        err_sys("pipe error");
    }
    
    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid > 0)
    {
        close(fd[0]);   //关闭读
        write(fd[1], "hello world!\n", 13);
        sleep(1);   //等子进程结束
    }
    else
    {
        close(fd[1]);
        n = read(fd[0], line, MAXLINE);
        write(STDOUT_FILENO, line, n);
    }
    exit(0);
}