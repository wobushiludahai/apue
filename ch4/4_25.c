/*
 * @Author: land sea
 * @Date: 2020-01-23 22:45:32
 * @LastEditTime : 2020-01-23 22:57:39
 * @LastEditors  : Please set LastEditors
 * @Description: 为每个命令行参数打印设备号
 * @FilePath: /apue/ch4/4_25.c
 */
#include "apue.h"
#include <sys/sysmacros.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    for(i = 1; i < argc; i++)
    {
        printf("%s: ", argv[i]);
        if(stat(argv[i], &buf) < 0)
        {
            err_ret("stat error");
            continue;
        }
        printf("dev = %d/%d", major(buf.st_dev), minor(buf.st_dev));

        if(S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
        {
            printf(" (%s) rdev = %d/%d", (S_ISCHR(buf.st_mode)) ? "character" : "block", major(buf.st_rdev), minor(buf.st_rdev));
        }
        printf("\n");
    }

    exit(0);
}