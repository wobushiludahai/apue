/*
 * @Author: land sea
 * @Date: 2020-01-27 22:10:54
 * @LastEditTime : 2020-01-27 22:16:51
 * @LastEditors  : Please set LastEditors
 * @Description: abort函数的一种实现
 * @FilePath: /apue/ch10/10_25.c
 */
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void abort(void)
{
    sigset_t mask;
    struct sigaction action;
    
    sigaction(SIGABRT, NULL, ＆action);
    if(action.sa)
}