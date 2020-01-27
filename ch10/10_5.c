/*
 * @Author: land sea
 * @Date: 2020-01-27 14:26:16
 * @LastEditTime : 2020-01-27 14:38:37
 * @LastEditors  : Please set LastEditors
 * @Description: 非可重入函数getpwnam
 * @FilePath: /apue/ch10/10_5.c
 */
#include "apue.h"
#include <pwd.h>

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

static void my_alarm(int signo)
{
    struct passwd *rootptr;

    printf("in signal handler\n");

    if((rootptr = getpwnam("root")) == NULL)
    {
        err_sys("getpwnam(root) error");
    }
    alarm(1);
}

int main(void)
{
    struct passwd *ptr;

    signal(SIGALRM, my_alarm);
    alarm(1);
    for(;;)
    {
        if((ptr = getpwnam("luhai")) == NULL)
        {
            err_sys("getpwnam error");
        }

        if(strcmp(ptr->pw_name, "luhai") != 0)
        {
            printf("return value corrupted!, pw_name = %s\n", ptr->pw_name);
        }
    }
}