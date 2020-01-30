/*
 * @Author: land sea
 * @Date: 2020-01-30 11:57:13
 * @LastEditTime : 2020-01-30 12:03:46
 * @LastEditors  : Please set LastEditors
 * @Description: popen测试
 * @FilePath: /apue/ch15/15_15.c
 */
#include "apue.h"
#include <sys/wait.h>

int main(void)
{
    char line[MAXLINE];
    FILE *fpin;

    if((fpin = popen("test", "r")) == NULL)
    {
        err_sys("popen error");
    }

    for(;;)
    {
        fputs("test> ", stdout);
        fflush(stdout);
        if(fgets(line, MAXLINE, fpin) == NULL)
        {
            break;
        }

        if(fputs(line, stdout) == EOF)
        {
            err_sys("fputs error to pipe");
        }
    }
    
    if(pclose(fpin) == -1)
    {
        err_sys("pclose error");
    }
    putchar('\n');
    exit(0);
}