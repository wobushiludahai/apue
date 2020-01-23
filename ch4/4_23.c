/*
 * @Author: land sea
 * @Date: 2020-01-23 22:32:50
 * @LastEditTime : 2020-01-23 22:35:12
 * @LastEditors  : Please set LastEditors
 * @Description: 使用chdir仅仅只改变当前进程的目录
 * @FilePath: /apue/ch4/4_23.c
 */
#include "apue.h"

int main(void)
{
    if(chdir("/tmp") < 0)
    {
        err_sys("chdir failes");
    }

    printf("chdir to /tmp succeeded\n");
    exit(0);
}