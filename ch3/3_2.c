/*
 * @Author: land sea
 * @Date: 2020-01-21 22:32:24
 * @LastEditTime : 2020-01-21 22:44:49
 * @LastEditors  : Please set LastEditors
 * @Description: 创建具有空洞的文件
 * @FilePath: /apue/ch3/3_2.c
 */

#include "apue.h"
#include <fcntl.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
    int fd;
    
    if((fd = creat("test.txt", FILE_MODE)) < 0)
    {
        err_sys("creat error");
    }

    if(write(fd, buf1, 10) != 10)
    {
        err_sys("buf1 write error");
    }

    if(lseek(fd, 1600, SEEK_SET) == -1)
    {
        err_sys("lseek error");
    }

    if(write(fd, buf2, 10) != 10)
    {
        err_sys("buf2 write error");
    }
    close(fd);

    exit(0);
}