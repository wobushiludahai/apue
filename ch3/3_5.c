/*
 * @Author: land sea
 * @Date: 2020-01-22 08:41:07
 * @LastEditTime : 2020-01-22 08:48:20
 * @LastEditors  : Please set LastEditors
 * @Description: 使用read和write复制文件
 * @FilePath: /apue/ch3/3_5.c
 */
#include "apue.h"

#define BUFFSIZE 4096

int main(void)
{
    int n;
    char buf[BUFFSIZE];

    while((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0)
    {
        if(write(STDOUT_FILENO, buf, n) != n)
        {
            err_sys("write error");
        }
    }
    
    if(n < 0)
    {
        err_sys("read error");
    }

    exit(0);
}