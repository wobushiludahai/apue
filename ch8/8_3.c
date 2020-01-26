/*
 * @Author: land sea
 * @Date: 2020-01-26 09:46:20
 * @LastEditTime : 2020-01-26 10:17:46
 * @LastEditors  : Please set LastEditors
 * @Description: vfork函数，其和fork有差异
 * @FilePath: /apue/ch8/8_3.c
 */
#include <unistd.h>
#include "apue.h"

int globvar = 6;

int main(void)
{
    int var;
    pid_t pid;

    var = 88;
    printf("before vfork\n");
    if((pid = vfork()) < 0)
    {
        err_sys("vfork error");
    }
    else if(pid == 0)
    {
        globvar++;
        var++;
        _exit(0);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    exit(0);
}