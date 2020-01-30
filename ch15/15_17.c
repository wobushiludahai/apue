/*
 * @Author: land sea
 * @Date: 2020-01-30 12:35:41
 * @LastEditTime : 2020-01-30 13:17:57
 * @LastEditors  : Please set LastEditors
 * @Description: 简单的协同进程示例
 * @FilePath: /apue/ch15/15_17.c
 */
#include "apue.h"

int main(void)
{
    int n, int1, int2;
    char line[MAXLINE];

    while((n = read(STDIN_FILENO, line, MAXLINE)) > 0)
    {
        line[n] = 0;
        if(sscanf(line, "%d%d", &int1, &int2) == 2)
        {
            sprintf(line, "%d\n", int1 + int2);
            n = strlen(line);
            if(write(STDOUT_FILENO, line, n) != n)
            {
                err_sys("write error");
            }
        }
        else
        {
            if(write(STDOUT_FILENO, "invalid args\n", 13) != 13)
            {
                err_sys("write error");
            }
        }
    }
    exit(0);
}