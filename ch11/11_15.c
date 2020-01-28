/*
 * @Author: land sea
 * @Date: 2020-01-28 21:02:10
 * @LastEditTime : 2020-01-28 21:16:19
 * @LastEditors  : Please set LastEditors
 * @Description: 条件变量和互斥量进行同步示例
 * @FilePath: /apue/ch11/11_15.c
 */
#include <pthread.h>

struct msg
{
    struct msg *m_next;
};

struct msg *workq;

pthread_cond_t qready = PTHREAD_COND_INITIALIZER;

pthread_mutex_t qlock = PTHREAD_MUTEX_INITIALIZER;

void process_msg(void)
{
    struct msg *mp;

    for(;;)
    {
        pthread_mutex_lock(&qlock);
        while(workq == NULL)
        {
            pthread_cond_wait(&qready, &qlock);
            mp = workq;
            workq = mp->m_next;
            pthread_mutex_unlock(&qlock);
        }
    }
}

void enqueue_msg(struct msg *mp)
{
    pthread_mutex_lock(&qlock);
    mp->m_next = workq;
    workq = mp;
    pthread_mutex_unlock(&qlock);
    pthread_cond_signal(&qready);
}
