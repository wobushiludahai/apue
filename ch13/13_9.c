/*
 * @Author: land sea
 * @Date: 2020-01-29 19:44:04
 * @LastEditTime : 2020-01-29 19:47:57
 * @LastEditors  : Please set LastEditors
 * @Description: 置执行时关闭标志
 * @FilePath: /apue/ch13/13_9.c
 */
#include "apue.h"
#include <fcntl.h>

int set_cloexec(int fd)
{
    int val;

    if((val = fcntl(fd, F_GETFD, 0)) < 0)
    {
        return (-1);
    }

    val |= FD_CLOEXEC;

    return (fcntl(fd, F_SETFD, val));
}