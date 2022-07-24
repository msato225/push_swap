#include "pushswap.h"

void    check()
{
    t_node *tmp = stack_a;

    printf("--- A ---\n");
    while (tmp)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
        if (tmp == stack_a)
            break;
    }

    tmp = stack_b;
    printf("--- B ---\n");
    while (tmp)
    {
        printf("%d\n", tmp->num);
        tmp = tmp->next;
        if (tmp == stack_b)
            break;
    }
}

void    push_b()
{
    printf(" [ pb ]\n");
    t_node *tmp;
    t_node *next;

    if (stack_a == NULL)
        return ;

    tmp = stack_a;
    next = tmp->next;

    if (tmp == next)
    {
        next = NULL;
    }
    else
    {
        tmp->prev->next = next;
        next->prev = tmp->prev;
    }
    stack_a = next;

    tmp->next = tmp;
    tmp->prev = tmp;

    if (stack_b == NULL)
    {
        stack_b = tmp;
        return ;
    }
    tmp->next = stack_b;
    tmp->prev = stack_b->prev;
    stack_b->prev->next = tmp;
    stack_b->prev = tmp;
    stack_b = tmp;
}

void    push_a()
{
    printf(" [ pa ]\n");
    t_node *tmp;
    t_node *next;

    if (stack_b == NULL)
        return ;
    tmp = stack_b;
    next = tmp->next;

    if (tmp == next)
        next = NULL;
    else
    {
        tmp->prev->next = next;
        next->prev = tmp->prev;
    }
    stack_b = next;

    tmp->next = tmp;
    tmp->prev = tmp;

    if (stack_a == NULL)
    {
        stack_a = tmp;
        return ;
    }
    tmp->next = stack_a;
    tmp->prev = stack_a->prev;
    stack_a->prev->next = tmp;
    stack_a->prev = tmp;

    stack_a = tmp;
}

void    swap_a()
{
    printf(" [ sa ]\n");
    t_node *ary[4];

    if (stack_a == NULL)
        return ;
    ary[0] = stack_a->prev;
    ary[2] = stack_a;
    ary[1] = stack_a->next;
    ary[3] = stack_a->next->next;
    if (ary[1] == ary[2])
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
        {
            ary[i]->next = ary[i + 1];
            printf("i = %d     %d\n", i, ary[i]->num);
        }
        else if (i == 1 || i == 2)
        {
            ary[i]->prev = ary[i - 1];
            ary[i]->next = ary[i + 1];
            printf("i = %d     %d\n", i, ary[i]->num);
        }
        else if (i == 3)
        {
            ary[i]->prev = ary[i - 1];
            printf("i = %d     %d\n", i, ary[i]->num);
        }
    }
    stack_a = ary[1];
}

void    swap_b()
{
    printf(" [ sb ]\n");
    t_node *ary[4];

    if (stack_b == NULL)
        return ;
    ary[0] = stack_b->prev;
    ary[1] = stack_b->next;
    ary[2] = stack_b;
    ary[3] = stack_b->next->next;
    if (ary[1] == ary[2])
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (i == 0)
            ary[i]->next = ary[i + 1];
        else if (i == 1 || i == 2)
        {
            ary[i]->prev = ary[i - 1];
            ary[i]->next = ary[i + 1];
        }
        else if (i == 3)
            ary[i]->prev = ary[i - 1];
    }
    stack_a = ary[1];
}

void    swap_ab()
{
    printf(" [ ss ]\n");
    swap_a();
    swap_b();
}

void    rotate_a()
{
    printf(" [ ra ]\n");

    if (stack_a == NULL)
        return ;
    stack_a = stack_a->next;
}

void    rotate_b()
{
    printf(" [ rb ]\n");

    if (stack_b == NULL)
        return ;
    stack_b = stack_b->next;
}

void	rotate_ab()
{
    printf(" [ rr ]\n");
    rotate_a();
    rotate_b();
}

void    rrotate_a()
{
    printf(" [ rra ]\n");

    if (stack_a == NULL)
        return ;
    stack_a = stack_a->prev;
}

void    rrotate_b()
{
    printf(" [ rrb ]\n");

    if (stack_b == NULL)
        return ;
    stack_b = stack_b->prev;
}

void    rrotate_ab()
{
    printf(" [ rrr ]\n");
    rrotate_a();
    rrotate_b();
}//
// Created by  on 2022/06/28.
//
