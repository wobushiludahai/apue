/*
 * @Author: land sea
 * @Date: 2020-01-26 19:25:15
 * @LastEditTime : 2020-01-26 19:29:10
 * @LastEditors  : Please set LastEditors
 * @Description: 输出所有命令行参数及全部环境表
 * @FilePath: /apue/ch8/8_17.c
 */
#include "apue.h"

int main(int argc, char *argv[])
{
    int i;
    char **ptr;
    extern char **environ;

    for(i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    for(ptr = environ; *ptr != 0; ptr++)
    {
        printf("%s\n", *ptr);
    }

    exit(0);
}