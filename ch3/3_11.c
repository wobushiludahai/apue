/*
 * @Author: land sea
 * @Date: 2020-01-22 09:32:15
 * @LastEditTime : 2020-01-22 09:53:19
 * @LastEditors  : Please set LastEditors
 * @Description: 第一个参数指定文件描述符，并对于该描述符打印其所选择的文件标志
 * @FilePath: /apue/ch3/3_11.c
 */
#include "apue.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int val;
    
    if(argc != 2)
    {
        err_quit("usage: a.out <description#>");
    }

    if((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0)
    {
        err_sys("fcntl error for fd %d", atoi(argv[1]));
    }

    switch(val & O_ACCMODE)
    {
        case O_RDONLY:
        {
            printf("read only");
            break;
        }

        case O_WRONLY:
        {
            printf("write only");
            break;
        }

        case O_RDWR:
        {
            printf("read and write");
            break;
        }

        default:
        {
            err_dump("unknown access mode");
        }
    }

    if(val & O_APPEND)
    {
        printf(", append");
    }
    if(val & O_NONBLOCK)
    {
        printf(", nonblocking");
    }
    if(val & O_SYNC)
    {
        printf(", synchronous writes");
    }

    #if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
        if(val & O_FSYNC)
        {
            printf(", synchronous writes");
        }
    #endif

    putchar('\n');
    exit(0);
}