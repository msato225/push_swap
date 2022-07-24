#include "pushswap.h"

void    checker()
{
    if (stack_a == NULL)
    {
        printf("stack_a is vacant\n");
        exit(EXIT_FAILURE);
    }
    else if (stack_b != NULL)
    {
        printf("stack_b is not vacant\n");
        exit(EXIT_FAILURE);
    }
    else
        return ;
}
int     str_check(char *str, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (isdigit((char)str[i]) != 1)
            return -1;
        else
            i++;
    }
    return 0;
}
void    check2(char *str)
{
    for (int i = 0; str[i]; i++)
    {
        printf("isdigit %c => %d\n", str[i], isdigit(str[i]));
    }
}
void    arg_check(char *argv[])
{
    for (int i = 1; argv[i]; i++)
    {
        printf("argv %s\n", argv[i]);
        check2(argv[i]);
    }
}
// Created by  on 2022/06/29.
//
