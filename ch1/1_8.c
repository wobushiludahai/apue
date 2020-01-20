/*
 * @Author: land sea
 * @Date: 2020-01-20 20:13:53
 * @LastEditTime : 2020-01-20 20:19:20
 * @LastEditors  : Please set LastEditors
 * @Description: 出错处理
 * @FilePath: /apue/ch1/1_8.c
 */
#include "apue.h"
#include <errno.h>

int main(int argc, char *argv[])
{
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}