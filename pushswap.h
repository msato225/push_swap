#ifndef PUSHSWAP_PUSHSWAP_H
#define PUSHSWAP_PUSHSWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int  nodes_num;
int smallest;

typedef struct    s_node
{
    int				num;
    struct  s_node	*next;
    struct  s_node	*prev;
    int             *head;
    int				index;
    int             compare;
}                t_node;

t_node *stack_a;
t_node *stack_b;
t_node *nodes;

void	reverse_stacka();
void	push_smallest();
void    q_sort(t_node *x[], int left, int right, int n);
void    sort(t_node *ary[], int ary_len);
void    checker();
void    show_data(t_node *x[], int n);
int     str_check(char *str, int n);
void    arg_check(char *argv[]);
void    check2(char *str);
void    check();
void    push_b();
void    push_a();
void    swap_a();
void    swap_b();
void    swap_ab();
void    rotate_a();
void    rotate_b();
void    rotate_ab();
void    rrotate_a();
void    rrotate_b();
void    rrotate_ab();
#endif //PUSHSWAP_PUSHSWAP_H
