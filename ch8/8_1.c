/*
 * @Author: land sea
 * @Date: 2020-01-26 09:05:46
 * @LastEditTime : 2020-01-26 09:12:39
 * @LastEditors  : Please set LastEditors
 * @Description: 子进程对变量更改是否影响父进程测试
 * @FilePath: /apue/ch8/8_1.c
 */
#include "apue.h"

int globvar = 6;
char buf[] = "a write to stdout\n";

int main(void)
{
    int var;
    pid_t pid;

    var = 88;
    if(write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf) -1)
    {
        err_sys("write error");
    }
    printf("before fork\n");

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        globvar++;
        var++;
    }
    else
    {
        sleep(2);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    exit(0);
}