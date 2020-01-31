/*
 * @Author: land sea
 * @Date: 2020-01-31 14:08:54
 * @LastEditTime : 2020-01-31 14:16:26
 * @LastEditors  : Please set LastEditors
 * @Description: UNIX域套接字绑定到地址
 * @FilePath: /apue/ch17/17_5.c
 */
#include "apue.h"
#include <sys/socket.h>
#include <sys/un.h>

int main(void)
{
    int fd, size;
    struct sockaddr_un un;

    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, "foo.socket");
    if((fd =socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
    {
        err_sys("socket failed");
    }
    size = offsetof(struct sockaddr_un, sun_path) + strlen(un.sun_path);
    if(bind(fd, (struct sockaddr *)&un, size) < 0)
    {
        err_sys("bind failed");
    }
    printf("UNIX domain socket bound\n");
    exit(0);
}