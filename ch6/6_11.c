/*
 * @Author: your name
 * @Date: 2020-01-25 11:14:03
 * @LastEditTime : 2020-01-25 11:38:46
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /apue/ch6/6_11.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    time_t t;
    struct tm *tmp;
    char buf1[16];
    char buf2[64];

    time(&t);
    tmp = localtime(&t);
    if(strftime(buf1, 16, "time and date: %r, %a %b %d, %Y", tmp) == 0)
    {
        printf("buffer length 16 is too small\n");
    }
    else
    {
        printf("%s\n", buf1);
    }

    if(strftime(buf2, 64, "time and date: %r, %a %b %d, %Y", tmp) == 0)
    {
        printf("buffer length 64 is too small\n");
    }
    else
    {
        printf("%s\n", buf2);
    }
    exit(0);
}