/*
 * @Author: land sea
 * @Date: 2020-01-26 18:38:57
 * @LastEditTime : 2020-01-26 18:48:11
 * @LastEditors  : Please set LastEditors
 * @Description: 优化为WAIT and TELL
 * @FilePath: /apue/ch8/8_13.c
 */
#include "apue.h"

static void charatatime(char *);

int main(void)
{
    pid_t pid;

    TELL_WAIT();
    if((pid = fork()) < 0)
    {
        err_sys("fork error");
    }
    else if(pid == 0)
    {
        WAIT_PARENT();
        charatatime("output from child\n");
    }
    else
    {
        charatatime("output from parent\n");
        TELL_CHILD(pid);
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