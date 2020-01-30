/*
 * @Author: land sea
 * @Date: 2020-01-30 22:52:36
 * @LastEditTime : 2020-01-30 22:58:59
 * @LastEditors  : Please set LastEditors
 * @Description: 分配和初始化套接字供服务器进程使用
 * @FilePath: /apue/ch16/16_12.c
 */
#include "apue.h"
#include <errno.h>
#include <sys/socket.h>

int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
    int fd;
    int err = 0;

    if((fd = socket(addr->sa_data, type, 0)) < 0)
    {
        return (-1);
    }
    
    if(bind(fd, addr, alen) < 0)
    {
        goto errout;
    }

    if(type == SOCK_STREAM || type == SOCK_SEQPACKET)
    {
        if(listen(fd, qlen) < 0)
        {
            goto errout;
        }
    }
    
    return (fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return (-1);
}