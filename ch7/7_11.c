/*
 * @Author: land sea
 * @Date: 2020-01-25 22:11:49
 * @LastEditTime : 2020-01-25 22:21:52
 * @LastEditors  : Please set LastEditors
 * @Description: setjmp/longjmp 函数
 * @FilePath: /apue/ch7/7_11.c
 */
#include "apue.h"
#include <setjmp.h>

#define TOK_ADD         5

void do_line(char *);
void cmd_add(void);
int get_token(void);

jmp_buf jmpbuffer;

int main(void)
{
    char line[MAXLINE];

    if(setjmp(jmpbuffer) != 0)
    {
        printf("error");
    }

    while(fgets(line, MAXLINE, stdin) != NULL)
    {
        do_line(line);
    }

    exit(0);
}

char *tok_ptr;

void do_line(char *ptr)
{
    int cmd;

    tok_ptr = ptr;
    while((cmd = get_token()) > 0)
    {
        switch(cmd)
        {
            case TOK_ADD:
            {
                cmd_add();
                break;
            }
        }
    }
}

void cmd_add(void)
{
    int token;

    token = get_token();
    if(token < 0)
    {
        //有错误产生,跳转
        longjmp(jmpbuffer, 1);
    }
}

int get_token(void)
{
    //根据ptr做匹配
}