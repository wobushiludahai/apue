/*
 * @Author: land sea
 * @Date: 2020-01-20 18:41:30
 * @LastEditTime : 2020-01-20 19:08:46
 * @LastEditors  : Please set LastEditors
 * @Description: cp 复制命令实现
 * @FilePath: /apue/ch1/1_4.c
 */
#include "apue.h"

#define BUFFSIZE 4096

int main(void)
{
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            err_sys("Write error");
        }
    }
    
    if(n < 0)
    {
        err_sys("read error");
    }

    exit(0);
}