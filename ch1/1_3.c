/*
 * @Author: land sea
 * @Date: 2020-01-20 18:59:27
 * @LastEditTime : 2020-01-20 19:08:27
 * @LastEditors  : Please set LastEditors
 * @Description: ls命令实现
 * @FilePath: /apue/ch1/1_3.c
 */
#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2)
    {
        err_quit("usage: ls directory_name");
    }

    if ((dp = opendir(argv[1])) == NULL)
    {
        err_sys("can't open %s", argv[1]);
    }

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}