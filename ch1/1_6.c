/*
 * @Author: land sea
 * @Date: 2020-01-20 19:20:24
 * @LastEditTime : 2020-01-20 19:25:23
 * @LastEditors  : Please set LastEditors
 * @Description: 打印程序ID
 * @FilePath: /apue/ch1/1_6.c
 */
#include "apue.h"

int main(void)
{
    printf("my process ID is %d\n", (long)getpid());
    exit(0);
}