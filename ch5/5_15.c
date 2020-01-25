/*
 * @Author: land sea
 * @Date: 2020-01-25 09:44:05
 * @LastEditTime : 2020-01-25 10:04:42
 * @LastEditors  : Please set LastEditors
 * @Description: 内存流操作
 * @FilePath: /apue/ch5/5_15.c
 */
#include "apue.h"

#define BSE 48

int main(void)
{
    FILE *fp;
    char buf[BSE];

    memset(buf, 'a', BSE-2);
    buf[BSE-2] = '\0';
    buf[BSE-1] = 'X';
    if((fp = fmemopen(buf, BSE, "w+")) == NULL)
    {
        err_sys("fmemopen failed");
    }
    printf("initial buffer contents: %s\n", buf);
    fprintf(fp, "hello, world");
    printf("before flush: %s\n", buf);
    fflush(fp);
    printf("after fflush: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    memset(buf, 'b', BSE-2);
    buf[BSE-2] = '\0';
    buf[BSE-1] = 'X';
    fprintf(fp, "hello, world");
    fseek(fp, 0, SEEK_SET);
    printf("after fseek:%s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    memset(buf, 'c', BSE-2);
    buf[BSE-2] = '\0';
    buf[BSE-1] = 'X';
    fprintf(fp, "hello, world");
    fclose(fp);
    printf("after fclose: %s\n", buf);
    printf("len of string in buf = %ld\n", (long)strlen(buf));

    return (0);    
}