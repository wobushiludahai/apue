/*
 * @Author:land sea
 * @Date: 2020-01-23 16:29:54
 * @LastEditTime : 2020-01-23 16:59:59
 * @LastEditors  : Please set LastEditors
 * @Description: umask函数
 * @FilePath: /apue/ch4/4_9.c
 */
#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)

int main(void)
{
    umask(0);
    if(creat("foo", RWRWRW) < 0)
    {
        err_sys("creat error for foo");
    }
    umask(S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    if(creat("bar", RWRWRW) < 0)
    {
        err_sys("creat error for bar");
    }
    exit(0);
}