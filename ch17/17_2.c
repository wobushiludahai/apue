/*
 * @Author: land sea
 * @Date: 2020-01-31 11:48:54
 * @LastEditTime : 2020-01-31 11:50:50
 * @LastEditors  : Please set LastEditors
 * @Description: socketpair函数
 * @FilePath: /apue/ch17/17_2.c
 */
#include "apue.h"
#include <sys/socket.h>

int fd_pipe(int fd[2])
{
    return (socketpair(AF_UNIX, SOCK_STREAM, 0, fd));
}