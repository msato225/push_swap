#include <stdio.h>
#include <stdlib.h>

typedef struct    s_node
{
    int                num;
    struct s_node    *next;
    struct s_node     *prev;
}                t_node;

t_node *stack_a = NULL;
t_node *stack_b = NULL;
t_node *nodes = NULL;
int        nodes_num = 0;

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
    t_node *tmp1;
    t_node *tmp2;
    int     tmp;

    if (stack_a == NULL)
        return ;
    tmp1 = stack_a;
    tmp2 = tmp1->next;

    if (tmp1 == tmp2)
        return ;
    else
    {
        tmp = tmp1->num;
        tmp1->num = tmp2->num;
        tmp2->num = tmp;
    }
}

void    swap_b()
{
    printf(" [ sb ]\n");
    t_node *tmp1;
    t_node *tmp2;
    int     tmp;

    if (stack_b == NULL)
        return ;
    tmp1 = stack_b;
    tmp2 = tmp1->next;

    if (tmp1 == tmp2)
        return ;
    else
    {
        tmp = tmp1->num;
        tmp1->num = tmp2->num;
        tmp2->num = tmp;
    }
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
}

int        main(int argc, char *argv[])
{
    printf("--- argv ---\n");
    for (int i = 1; i < argc; i++)
        printf("%s\n", argv[i]);

    nodes_num = argc - 1;

    t_node *nodes = malloc(sizeof(t_node) * nodes_num);

    //set num
    for (int i = 0; i < nodes_num; i++)
    {
        nodes[i].num = atoi(argv[i + 1]);
    }
    //check
    printf("--- check ---\n");
    for (int i = 0; i < nodes_num; i++)
    {
        printf("num = %d\n", nodes[i].num);
    }
    //join node
    for (int i = 0; i < nodes_num; i++)
    {
        if (i == 0)
        {
            nodes[0].prev = &nodes[nodes_num - 1];
            nodes[i].next = &nodes[i + 1];
        }
        else if (i == nodes_num - 1)
        {
            nodes[i].prev = &nodes[i - 1];
            nodes[i].next = &nodes[0];
        }
        else
        {
            nodes[i].prev = &nodes[i - 1];
            nodes[i].next = &nodes[i + 1];

        }
    }
    stack_a = nodes;

    // === execute ===
    check();
    push_b();
    push_b();
    push_b();
    check();
    rotate_a();
	check();
    rrotate_a();
    check();
    swap_a();
    check();
    swap_b();
    check();
	rotate_b();
	check();
    rrotate_b();
    check();
    rrotate_ab();
    check();
    swap_ab();
    check();
}

