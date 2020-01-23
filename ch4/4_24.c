/*
 * @Author: land sea
 * @Date: 2020-01-23 22:36:08
 * @LastEditTime : 2020-01-23 22:40:32
 * @LastEditors  : Please set LastEditors
 * @Description: getcwd函数
 * @FilePath: /apue/ch4/4_24.c
 */
#include "apue.h"

int main(void)
{
    char *ptr;
    size_t size;
    if(chdir("/tmp") < 0)
    {
        err_sys("chdir failed");
    }

    ptr = path_alloc(&size);

    if(getcwd(ptr, size) == NULL)
    {
        err_sys("getcwd failed");
    }
    
    printf("cwd = %s\n", ptr);
    exit(0);
}