/*
 * @Author: land sea
 * @Date: 2020-01-22 13:03:42
 * @LastEditTime : 2020-01-22 13:10:02
 * @LastEditors  : Please set LastEditors
 * @Description: access函数的使用方法
 * @FilePath: /apue/ch4/4_8.c
 */
#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        err_quit("usage: a.out <pathname>");
    }

    if(access(argv[1], R_OK) < 0)
    {
        err_ret("access error for %s", argv[1]);
    }
    else
    {
        printf("read access OK\n");
    }

    if(open(argv[1], O_RDONLY) < 0)
    {
        err_ret("open error for %s", argv[1]);
    }
    else
    {
        printf("open for reading OK\n");
    }

    exit(0);
}