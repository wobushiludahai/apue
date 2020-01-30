/*
 * @Author: land sea
 * @Date: 2020-01-30 08:54:44
 * @LastEditTime : 2020-01-30 09:07:21
 * @LastEditors  : Please set LastEditors
 * @Description: readn 和　writen的实现
 * @FilePath: /apue/ch14/14_24.c
 */
#include "apue.h"

ssize_t read(int fd, void *ptr, size_t n)
{
    size_t nleft;
    ssize_t nread;

    nleft = n;
    while(nleft > 0)
    {
        if((nread = read(fd, ptr, nleft)) < 0)
        {
            if(nleft == n)
            {
                return(-1);
            }
            else
            {
                break;
            }
        }
        else if(nread == 0)
        {
            break;
        }
        nleft -= nread;
        ptr += nread;
    }
    return (n - nleft);
}

ssize_t writen(int fd, const void *ptr, size_t n)
{
    size_t nleft;
    ssize_t nwritten;

    nleft = n;
    while(nleft > 0)
    {
        if((nwritten = write(fd, ptr, nleft)) < 0)
        {
            if(nleft == 0)
            {
                return (-1);
            }
            else
            {
                break;
            }
        }
        else if(nwritten == 0)
        {
            break;
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return (n - nleft);
}