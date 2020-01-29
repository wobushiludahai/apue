/*
 * @Author: land sea
 * @Date: 2020-01-29 21:03:09
 * @LastEditTime : 2020-01-29 21:07:55
 * @LastEditors  : Please set LastEditors
 * @Description: 测试一把锁
 * @FilePath: /apue/ch14/14_6.c
 */
#include "apue.h"
#include <fcntl.h>

pid_t lock_test(int fd, int type, off_t offset, int whence, off_t len)
{
    struct flock lock;
    
    lock.l_type = type;
    lock.l_start = offset;
    lock.l_whence = whence;
    lock.l_len = len;

    if(fcntl(fd, F_GETLK, &lock) < 0)
    {
        err_sys("fcntl error");
    }

    if(lock.l_type == F_UNLCK)
    {
        return (0);
    }
    return (lock.l_pid);
}