/*
 * @Author: land sea
 * @Date: 2020-01-25 20:55:32
 * @LastEditTime : 2020-01-25 22:00:23
 * @LastEditors  : Please set LastEditors
 * @Description: atexit函数
 * @FilePath: /apue/ch7/7_3.c
 */
#include "apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
    if(atexit(my_exit2) != 0)
    {
        err_sys("can't register my_exit2");
    }

    if(atexit(my_exit1) != 0)
    {
        err_sys("can't register my_exit1");
    }

    if(atexit(my_exit1) != 0)
    {
        err_sys("can't register my_exit1");
    }

    printf("main is done\n");
    
    return (0);
}

static void my_exit1(void)
{
    printf("first exit handler\n");
}

static void my_exit2(void)
{
    printf("second exit handler\n");
}