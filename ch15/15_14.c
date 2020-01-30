/*
 * @Author: land sea
 * @Date: 2020-01-30 11:52:57
 * @LastEditTime : 2020-01-30 11:55:39
 * @LastEditors  : Please set LastEditors
 * @Description: for testing
 * @FilePath: /apue/ch15/15_14.c
 */
#include "apue.h"
#include <ctype.h>

int main(void)
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(isupper(c))
        {
            c = tolower(c);
        }
        
        if(putchar(c) == EOF)
        {
            err_sys("output error");
        }

        if(c == '\n')
        {
            fflush(stdout);
        }
    }
}