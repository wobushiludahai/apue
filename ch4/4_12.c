/*
 * @Author: land sea
 * @Date: 2020-01-23 18:21:45
 * @LastEditTime : 2020-01-23 18:30:44
 * @LastEditors  : Please set LastEditors
 * @Description: 使用chmod更改权限
 * @FilePath: /apue/ch4/4_12.c
 */
#include "apue.h"

int main(void)
{
    struct stat statbuf;

    if(stat("foo", &statbuf) < 0)
    {
        err_sys("stat error for foo");
    }

    if(chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID))
    {
        err_sys("chmod error for foo");
    }

    if(chmod("bar", S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH) < 0)
    {
        err_sys("chmod error for bar");
    }

    exit(0);
}
