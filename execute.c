#include "pushswap.h"

// void execute()
// {
// 	int head;

// 	head = stack_a->index;
// 	while (stack_a->next->index != head)
// 	{
// 		if (stack_a->index > stack_a->next->index)
// 		{
// 			push_b();
// 			check();
// 		}
// 		else if (stack_a->index < stack_a->next->index)
//         {
// 		    rotate_a();
// 			check();
// 		}
// 		else
// 			return ;
//     }
// }

void	push_smallest()
{
	printf("push_smallest\n");
	t_node *tmp = malloc(sizeof(t_node));

	//find the smallest
	while(1)
	{
		if (stack_a == NULL)
		{
			reverse_stacka();
			return ;
		}
		tmp = stack_a;
		smallest = tmp->index;
		while(1)
		{
			if (smallest > tmp->next->index)
				smallest = tmp->next->index;
			tmp = tmp->next;
			if (tmp == stack_a)
				break;
		}
		printf("smallest = %d\n", smallest);
		while(1)
		{	
			
			if (stack_a->index == smallest)
			{
				push_b();
				check();
				break ;
			}
			else
			{
				rotate_a();
				check();
				break ;
			}
		}
	}
}

void	reverse_stacka()
{
	printf("reverse from B to A\n");
	while(stack_b != NULL)
		push_a();
		check();
	return ;
}