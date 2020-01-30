/*
 * @Author: land sea
 * @Date: 2020-01-30 22:35:13
 * @LastEditTime : 2020-01-30 22:42:32
 * @LastEditors  : Please set LastEditors
 * @Description: 处理瞬时connect错误的方法
 * @FilePath: /apue/ch16/16_10.c
 */
#include "apue.h"
#include <sys/socket.h>

#define MAXSLEEP 128

int connect_retry(int sockfd, const struct sockaddr *addr, socklen_t alen)
{
    int numsec;

    for(numsec = 1; numsec <= MAXSLEEP; numsec<<1)
    {
        if(connect(sockfd, addr, alen) == 0)
        {
            //连接成功
            return (0);
        }
        
        if(numsec <= MAXSLEEP/2)
        {
            sleep(numsec);
        }
    }
    return (-1);
}