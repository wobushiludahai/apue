/*
 * @Author: land sea
 * @Date: 2020-01-28 23:22:12
 * @LastEditTime : 2020-01-28 23:27:36
 * @LastEditors  : Please set LastEditors
 * @Description: 以分离状态创建线程
 * @FilePath: /apue/ch12/12_4.c
 */
#include "apue.h"
#include <pthread.h>

int makethread(void *(*fn)(void *), void *arg)
{
    int err;
    pthread_t tid;
    pthread_attr_t attr;
    
    err = pthread_attr_init(&attr);
    if(err != 0)
    {
        return (err);
    }
    
    err = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if(err == 0)
    {
        err = pthread_create(&tid, &attr, fn, arg);
    }
    pthread_attr_destroy(&attr);
    return(err);
}