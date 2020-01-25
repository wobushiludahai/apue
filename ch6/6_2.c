/*
 * @Author: your name
 * @Date: 2020-01-25 10:41:14
 * @LastEditTime : 2020-01-25 10:48:32
 * @LastEditors  : Please set LastEditors
 * @Description: getpwnam函数实现
 * @FilePath: /apue/ch6/6_2.c
 */
#include <pwd.h>
#include <string.h>
#include <stddef.h>

struct passwd *getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();

    while((ptr = getpwent()) != NULL)
    {
        if(strcmp(name, ptr->pw_name) == 0)
        {
            break;
        }
    }

    endpwent();
    return (ptr);
}