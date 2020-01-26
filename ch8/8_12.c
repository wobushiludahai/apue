/*
 * @Author: land sea
 * @Date: 2020-01-26 18:30:50
 * @LastEditTime : 2020-01-26 18:38:37
 * @LastEditors  : Please set LastEditors
 * @Description: 进程运行顺序测试
 * @FilePath: /apue/ch8/8_12.c
 */
#include "apue.h"

static void charatatime(char *);

int main(void)
{
    pid_t pid;

    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
    }
    
    exit(0);
}

static void charatatime(char *str)
{
    char *ptr;
    int c;

    setbuf(stdout, NULL);
    for(ptr = str; (c = *ptr++)!=0;)
    {
        putc(c, stdout);
    }
}