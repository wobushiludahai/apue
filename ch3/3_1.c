/*
 * @Author: land sea
 * @Date: 2020-01-21 22:09:16
 * @LastEditTime : 2020-01-21 22:30:46
 * @LastEditors  : Please set LastEditors
 * @Description: 标注输入设置偏移量
 * @FilePath: /apue/ch3/3_1.c
 */
#include "apue.h"

int main(void)
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
    {
        printf("cannot seek\n");
    }
    else
    {
        printf("seek ok\n");
    }

    exit(0);
}
