/*
 * @Author: land sea
 * @Date: 2020-01-20 18:57:56
 * @LastEditTime : 2020-01-20 19:14:09
 * @LastEditors  : Please set LastEditors
 * @Description: read and write
 * @FilePath: /apue/ch1/1_5.c
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