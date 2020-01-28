/*
 * @Author: land sea
 * @Date: 2020-01-28 17:14:41
 * @LastEditTime : 2020-01-28 17:59:25
 * @LastEditors  : Please set LastEditors
 * @Description: foo_alloc/foo_hold/foo_rele
 * @FilePath: /apue/ch11/11_10.c
 */
#include <stdlib.h>
#include <pthread.h>

struct foo
{
    int f_count;
    pthread_mutex_t f_lock;
    int f_id;
    //more args
};

struct foo *foo_alloc(int id)
{
    struct foo *fp;
    
    if((fp = malloc(sizeof(struct foo))) != NULL)
    {
        fp->f_count = 1;
        fp->f_id  = id;
        if(pthread_mutex_init(&fp->f_lock, NULL) != 0)
        {
            free(fp);
            return (NULL);
        }
        //more initializations
    }

    return(fp);
}

void foo_hold(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);
    fp->f_count++;
    pthread_mutex_unlock(&fp->f_lock);
}

void foo_rele(struct foo *fp)
{
    pthread_mutex_lock(&fp->f_lock);
    if(--fp->f_count == 0)
    {
        pthread_mutex_unlock(&fp->f_lock);
        pthread_mutex_destroy(&fp->f_lock);
        free(fp);
    }
    else
    {
        pthread_mutex_unlock(&fp->f_lock);
    }
}