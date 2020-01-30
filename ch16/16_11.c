/*
 * @Author: land sea
 * @Date: 2020-01-30 22:42:42
 * @LastEditTime : 2020-01-30 22:48:13
 * @LastEditors  : Please set LastEditors
 * @Description: 移植性更好的版本
 * @FilePath: /apue/ch16/16_11.c
 */
#include "apue.h"
#include <sys/socket.h>

#define MAX_SLEEP 128

int connect_retry(int domain, int type, int protocol, const struct sockaddr *addr, socklen_t alen)
{
    int numsec, fd;
    
    for(numsec = 1; numsec <= MAX_SLEEP; numsec <<= 1)
    {
        if((fd = socket(domain, type, protocol)) < 0)
        {
            return (-1);
        }

        if(connect(fd, addr, alen) == 0)
        {
            //连接成功
            return (fd);
        }

        close(fd);
        if(numsec <= MAX_SLEEP/2)
        {
            sleep(numsec);
        }
    }

    return (-1);
}