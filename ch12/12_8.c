/*
 * @Author: land sea
 * @Date: 2020-01-28 23:50:31
 * @LastEditTime : 2020-01-28 23:52:33
 * @LastEditors  : Please set LastEditors
 * @Description: 递归互斥信号量示例
 * @FilePath: /apue/ch12/12_8.c
 */
#include "apue.h"
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

extern int makethread(void *(*)(void *), void *);