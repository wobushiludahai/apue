/*
 * @Author: land sea
 * @Date: 2020-01-29 11:12:17
 * @LastEditTime : 2020-01-29 11:32:36
 * @LastEditors  : Please set LastEditors
 * @Description: getenv线程安全版本
 * @FilePath: /apue/ch12/12_13.c
 */
#include <limits.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

#define MAXSTRINGSZ 4096

static pthread_key_t key;
static pthread_once_t inti_done = PTHREAD_ONCE_INIT;
pthread_mutex_t env_mutex = PTHREAD_MUTEX_INITIALIZER;

extern char **environ;

static void thread_init(void)
{
    pthread_key_create(&key, free);
}

char *getenv(const char *name)
{
    int i, len;
    char *envbuf;
    
    pthread_once(&inti_done, thread_init);//保证thread_init只调用一次
    pthread_mutex_lock(&env_mutex);
    envbuf = (char *)pthread_getspecific(key);
    if(envbuf == NULL)
    {
        envbuf = malloc(MAXSTRINGSZ);
        if(envbuf == NULL)
        {
            pthread_mutex_unlock(&env_mutex);
            return (NULL);
        }
        pthread_setspecific(key, envbuf);
    }
    len = strlen(name);
    for(i = 0; environ[i] != NULL; i++)
    {
        if((strncmp(name, environ[i], len) == 0) && (environ[i][len] == '='))
        {
            strncpy(envbuf, &environ[i][len+1], MAXSTRINGSZ - 1);
            pthread_mutex_unlock(&env_mutex);
            return (envbuf);
        }
    }
    pthread_mutex_unlock(&env_mutex);
    return (NULL);
}