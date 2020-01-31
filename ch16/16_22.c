/*
 * @Author: land sea
 * @Date: 2020-01-31 11:23:37
 * @LastEditTime : 2020-01-31 11:30:43
 * @LastEditors  : Please set LastEditors
 * @Description: 使用套接字选项设置允许绑定同一地址
 * @FilePath: /apue/ch16/16_22.c
 */
#include "apue.h"
#include <errno.h>
#include <sys/socket.h>

int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
    int fd, err;
    int reuse = 1;

    if((fd = socket(addr->sa_family, type, 0)) < 0)
    {
        return (-1);
    }
    
    if(setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(int)) < 0)
    {
        goto errout;
    }
    if(bind(fd, addr, alen) < 0)
    {
        goto errout;
    }
    if(type == SOCK_DGRAM || type == SOCK_SEQPACKET)
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