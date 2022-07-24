#include "pushswap.h"

int        main(int argc, char *argv[])
{
    nodes_num = argc - 1;
    stack_a = NULL;
    stack_b = NULL;
    t_node  *nodes = malloc(sizeof(t_node) * nodes_num);
    //check
    printf("--- status check ---\n");
    if (argc < 2)
    {
        printf("You need command line arguments\n");
        return -1;
    }
    printf("--- number check ---\n");
    arg_check(argv);
    for(int i = 1; i < nodes_num; i++)
    {
        if ((str_check(argv[i], strlen(argv[i]))) != 0)
        {
            printf("only numbers can be used\n");
            return -1;
        }
    }
    for(int i = 0; i < nodes_num; i++)
    {
        nodes[i].num = atoi(argv[i + 1]);
    }
    if(!nodes)
    {
        printf("error\n");
        return -1;
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

    t_node *ary_node[100];
    int i = 0;
    int j = 1;
    for (i = 0; i < nodes_num; i++, j++)
        ary_node[i] = &nodes[i];
    sort(ary_node, nodes_num);
    printf("=== sort index ===\n");
    for (i = 0; i < nodes_num; i++)
        ary_node[i]->index = i;
    for (i = 0; i < nodes_num; i++)
    {
        printf("nodes_num  = %d\n", nodes[i].num);
        printf("nodes_index  = %d\n", nodes[i].index);
    }
    //q_sort(ary_node, 0, nodes_num, nodes_num);
    printf("=== execute ===\n");
    checker();
    check();
    push_smallest();
    check();

    //printf("=== use stack ===\n");
    //t_node  *tmp = stack_a;
    //int     pivot = nodes_num / 2;

    // while (1)
    // {
    //     check();
    //     printf("=== sort ===\n");
    //     if (stack_a->index < stack_a->next->index)
    //         swap_a();
    //     else
    //     {
    //         rotate_a();
    //     }

    //     if (tmp == stack_a)
    //         break;
    // }
    // check();
}

