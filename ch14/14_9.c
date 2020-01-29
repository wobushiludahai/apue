/*
 * @Author: land sea
 * @Date: 2020-01-29 21:50:28
 * @LastEditTime : 2020-01-29 21:54:28
 * @LastEditors  : Please set LastEditors
 * @Description: lockfile函数
 * @FilePath: /apue/ch14/14_9.c
 */
#include <unistd.h>
#include <fcntl.h>

int lockfile(int fd)
{
    struct flock fl;

    fl.l_type = F_WRLCK;
    fl.l_start = 0;
    fl.l_whence = SEEK_SET;
    fl.l_len = 0;
    return (fcntl(fd, F_SETLK, &fl));
}

//另一种实现
// #define lockfile(fd) write_lock((fd), 0, SEEK_SET, 0)