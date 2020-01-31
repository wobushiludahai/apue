/*
 * @Author: land sea
 * @Date: 2020-01-31 10:43:52
 * @LastEditTime : 2020-01-31 11:09:06
 * @LastEditors  : Please set LastEditors
 * @Description: 无连接uptime数据报版本
 * @FilePath: /apue/ch16/16_20.c
 */
#include "apue.h"
#include <netdb.h>
#include <errno.h>
#include <syslog.h>
#include <sys/socket.h>

#define BUFLEN 128
#define MAXADDRLEN  256

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 256
#endif

int initserver(int type, const struct sockaddr *addr, socklen_t alen, int qlen)
{
    int fd;
    int err = 0;

    if((fd = socket(addr->sa_data, type, 0)) < 0)
    {
        return (-1);
    }
    
    if(bind(fd, addr, alen) < 0)
    {
        goto errout;
    }

    if(type == SOCK_STREAM || type == SOCK_SEQPACKET)
    {
        if(listen(fd, qlen) < 0)
        {
            goto errout;
        }
    }
    
    return (fd);

errout:
    err = errno;
    close(fd);
    errno = err;
    return (-1);
}

void serve(int sockfd)
{
    int n;
    socklen_t alen;
    FILE *fp;
    char buf[BUFLEN];
    char abuf[MAXADDRLEN];
    struct sockaddr *addr = (struct sockaddr *)abuf;

    set_cloexec(sockfd);
    for(;;)
    {
        alen = MAXADDRLEN;
        if((n = recvfrom(sockfd, buf, BUFLEN, 0, addr, &alen)) < 0)
        {
            syslog(LOG_ERR, "ruptimed: recvfrom error: %s", strerror(errno));
            exit(1);
        }
        if((fp = popen("/usr/bin/uptime", "r")) == NULL)
        {
            sprintf(buf, "error: %s\n", strerror(errno));
            sendto(sockfd, buf, strlen(buf), 0, addr, alen);
        }
        else
        {
            if(fgets(buf, BUFLEN, fp) != NULL)
            {
                sendto(sockfd, buf, strlen(buf), 0, addr, alen);
            }
            pclose(fp);
        }
    }
}

int main(int argc, char *argv[])
{
    struct addrinfo *ailist, *aip;
    struct addrinfo hint;
    int sockfd, err, n;
    char *host;

    if(argc != 1)
    {
        err_quit("usage: ruptimed");
    }
    if((n = sysconf(_SC_HOST_NAME_MAX)) < 0)
    {
        n = HOST_NAME_MAX;
    }
    if((host = malloc(n)) == NULL)
    {
        err_sys("malloc error");
    }
    if(gethostname(host, n) < 0)
    {
        err_sys("gethostname error");
    }
    
    daemonize("ruptimed");
    memset(&hint, 0, sizeof(hint));
    hint.ai_flags = AI_CANONNAME;
    hint.ai_socktype = SOCK_DGRAM;
    hint.ai_canonname = NULL;
    hint.ai_addr = NULL;
    hint.ai_next = NULL;
    
    if((err = getaddrinfo(host, "ruptime", &hint, &ailist)) != 0)
    {
        syslog(LOG_ERR, "ruptimed: getaddrinfo error: %s", gai_strerror(err));
        exit(1);
    }

    for(aip = ailist; aip != NULL; aip = aip->ai_next)
    {
        if((sockfd = initserver(SOCK_DGRAM, aip->ai_addr, aip->ai_addrlen, 0)) >= 0)
        {
            serve(sockfd);
            exit(0);
        }
    }
}