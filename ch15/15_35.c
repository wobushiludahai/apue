/*
 * @Author: land sea
 * @Date: 2020-01-30 19:35:26
 * @LastEditTime : 2020-01-30 20:10:27
 * @LastEditors  : Please set LastEditors
 * @Description: 基于信号量的互斥原语实现
 * @FilePath: /apue/ch15/15_35.c
 */
#include "slock.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

struct slock *s_alloc(void)
{
    struct slock *sp;
    static int cnt;

    if((sp = malloc(sizeof(struct slock))) == NULL)
    {
        return (NULL);
    }

    do
    {
        snprintf(sp->name, sizeof(sp->name),"/%ld.%d", (long)getpid(), cnt++);
        sp->semp = sem_open(sp->name, O_CREAT|O_EXEL, S_IRWXU, 1);
    }
    while((sp->semp == SEM_FAILED) && (errno == EEXIST));
    
    if(sp->semp == SEM_FAILED)
    {
        free(sp);
        return (NULL);
    }
    sem_unlink(sp->name);
    return(sp);
}

void s_free(struct slock *sp)
{
    sem_close(sp->semp);
    free(sp);
}

int s_lock(struct slock *sp)
{
    return (sem_wait(sp->semp));
}

int s_trylock(struct slock *sp)
{
    return (sem_trywait(sp->semp));
}

int s_unlock(struct slock *sp)
{
    return (sem_post(sp->semp));
}