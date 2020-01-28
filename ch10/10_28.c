/*
 * @Author: land sea
 * @Date: 2020-01-28 09:46:07
 * @LastEditTime : 2020-01-28 10:11:52
 * @LastEditors  : Please set LastEditors
 * @Description: system函数的另一种实现
 * @FilePath: /apue/ch10/10_28.c
 */
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

int system(const char *cmdstring)
{
    pid_t pid;
    int status;
    struct sigaction ignore, saveintr, savequit;
    sigset_t chldmask, savemask;

    if(cmdstring == NULL)
    {
        return (1);
    }

    ignore.sa_handler = SIG_IGN;
    sigemptyset(&ignore.sa_mask);
    ignore.sa_flags = 0;
    if(sigaction(SIGINT, &ignore, &saveintr) < 0)
    {
        return (-1);
    }

    if(sigaction(SIGQUIT, &ignore, &savequit) < 0)
    {
        return (-1);
    }
    
    sigemptyset(&chldmask);
    sigaddset(&chldmask, SIGCHLD);
    if(sigprocmask(SIG_BLOCK, &chldmask, &savemaask) < 0)
    {
        return (-1);
    }

    if((pid = fork()) < 0)
    {
        status = -1;
    }
    else if(pid == 0)
    {
        sigaction(SIGINT, &saveintr, NULL);
        sigaction(SIGQUIT, &savequit, NULL);
        sigprocmask(SIG_SETMASK, &savemask, NULL);

        execl("/bin/sh", "sh", "-c", cmdstring, (char *)0);
        _exit(127);
    }
    else
    {
        while(waitpid(pid, &status, 0) < 0)
        {
            if(errno != EINTR)
            {
                status = -1;
                break;
            }
        }
    }

    if(sigaction(SIGINT, &saveintr, NULL) < 0)
    {
        return (-1);
    }
    
    if(sigaction(SIGQUIT, &savequit, NULL) < 0)
    {
        return (-1);
    }

    if(sigaction(SIG_SETMASK, &savemask, NULL) < 0)
    {
        return (-1);
    }

    return (status);
}