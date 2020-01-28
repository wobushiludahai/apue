/*
 * @Author: your name
 * @Date: 2020-01-28 12:00:01
 * @LastEditTime : 2020-01-28 12:33:50
 * @LastEditors  : Please set LastEditors
 * @Description: 打印进程ID 新线程ID 初始化线程的ID
 * @FilePath: /apue/ch11/11_2.c
 */
#include "apue.h"
#include <pthread.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %lu tid %lu (0x%lx)\n", s, (unsigned long)pid, (unsigned long)tid, (unsigned long)tid);
}

void *thr_fn(void *arg)
{
    printids("new thread:");
    return ((void *)0);
}

int main(void)
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, NULL);
    if(err != 0)
    {
        err_exit(err, "can't create thread");
    }
    printids("main thread:");
    sleep(1);
    exit(0);
}