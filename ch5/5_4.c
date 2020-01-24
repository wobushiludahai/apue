/*
 * @Author: land sea
 * @Date: 2020-01-24 11:19:37
 * @LastEditTime : 2020-01-24 11:22:20
 * @LastEditors  : Please set LastEditors
 * @Description: getc and puts
 * @FilePath: /apue/ch5/5_4.c
 */
#include "apue.h"

int main(void)
{
    int c;

    while((c = getc(stdin)) != EOF)
    {
        if(putc(c, stdout) == EOF)
        {
            err_sys("output error");
        }
    }

    if(ferror(stdin))
    {
        err_sys("input error");
    }

    exit(0);
}