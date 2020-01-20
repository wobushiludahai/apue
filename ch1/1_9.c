/*
 * @Author: land sea
 * @Date: 2020-01-20 20:23:28
 * @LastEditTime : 2020-01-20 20:27:05
 * @LastEditors  : Please set LastEditors
 * @Description: 打印用户ID和用户组ID
 * @FilePath: /apue/ch1/1_9.c
 */
#include "apue.h"

int main(void)
{
    printf("uid = %d, group id = %d\n", getuid(), getgid());
    exit(0);
}