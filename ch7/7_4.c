/*
 * @Author: land sea
 * @Date: 2020-01-25 21:14:44
 * @LastEditTime : 2020-01-25 21:17:44
 * @LastEditors  : Please set LastEditors
 * @Description: 输出命令行
 * @FilePath: /apue/ch7/7_4.c
 */
#include "apue.h"

int main(int argc, char *argv[])
{
    int i;
    
    for(i = 0; i < argc; i++)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }

    exit(0);
}