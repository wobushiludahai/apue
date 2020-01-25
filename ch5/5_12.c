/*
 * @Author: land sea
 * @Date: 2020-01-25 08:37:47
 * @LastEditTime : 2020-01-25 08:57:37
 * @LastEditors  : Please set LastEditors
 * @Description: 创建临时文件
 * @FilePath: /apue/ch5/5_12.c
 */
#include "apue.h"

int main(void)
{
    char name[L_tmpnam], line[MAXLINE];
    FILE *fp;

    printf("%s\n", tmpnam(NULL));

    tmpnam(name);
    printf("%s\n", name);

    if((fp = tmpfile()) == NULL)
    {
        err_sys("tempfile error");
    }
    fputs("one line of output\n", fp);
    rewind(fp);
    if(fgets(line, MAXLINE, fp) == NULL)
    {
        err_sys("fgets error");
    }
    fputs(line, stdout);

    exit(0);
}