/*
 * @Author: land sea
 * @Date: 2020-01-23 19:24:59
 * @LastEditTime : 2020-01-23 19:40:51
 * @LastEditors  : Please set LastEditors
 * @Description: unlink函数
 * @FilePath: /apue/ch4/4_16.c
 */
#include "apue.h"
#include <fcntl.h>

int main(void)
{
    if(open("bar", O_RDWR) < 0)
    {
        err_sys("open error");
    }

    if(unlink("bar") < 0)
    {
        err_sys("unlink error");
    }

    printf("file--bar unlinked");

    sleep(15);
}