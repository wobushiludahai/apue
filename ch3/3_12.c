/*
 * @Author: your name
 * @Date: 2020-01-22 10:04:01
 * @LastEditTime : 2020-01-22 10:13:31
 * @LastEditors  : Please set LastEditors
 * @Description: 设置或者清标志位
 * @FilePath: /apue/ch3/3_12.c
 */
#include "apue.h"
#include <fcntl.h>

void set_f1(int fd, int flags)
{
    int val;
    
    if((val = fcntl(fd, F_GETFL, 0)) < 0)
    {
        err_sys("fcntl get args error");
    }

    val |= flags;       //置标志位
    // val &= ~flags;      //清标志位

    if(fcntl(fd, val, 0) < 0)
    {
        err_sys("fcntl set args error");
    }
}