/*
 * @Author: land sea
 * @Date: 2020-01-29 20:16:19
 * @LastEditTime : 2020-01-29 20:24:06
 * @LastEditors  : Please set LastEditors
 * @Description: 非阻塞IO实例
 * @FilePath: /apue/ch14/14_1.c
 */
#include "apue.h"
#include <errno.h>
#include <fcntl.h>

char buf[500000];

int main(void)
{
    int ntowrite, nwrite;
    char *ptr;

    ntowrite = read(STDIN_FILENO, buf, sizeof(buf));
    fprintf(stderr, "read %d bytes\n", ntowrite);

    set_fl(STDOUT_FILENO, O_NONBLOCK);
    ptr = buf;
    while(ntowrite > 0)
    {
        errno = 0;
        nwrite = write(STDOUT_FILENO, ptr, ntowrite);
        fprintf(stderr, "nwrite = %d, errno = %d\n", nwrite, errno);

        if(nwrite > 0)
        {
            ptr += nwrite;
            ntowrite -= nwrite;
        }
    }
    
    clr_fl(STDOUT_FILENO, O_NONBLOCK);
    
    exit(0);
}