#include "pushswap.h"

void swap(t_node *x[], int i, int j)
{
    t_node *temp;

    temp = x[i];
    x[i] = x[j];
    x[j] = temp;
    printf("======swap stack\n");
    int k = 0;
    while (k < nodes_num)
    {
        printf("%d\n", x[k]->num);
        k++;
    }
    printf("swap done=======\n");
}

void	show_data(t_node *x[], int n)
{
    int i;

    printf("%d\n  ", n);
    for (i = 0; i < n ; i++)
    {
        printf("%d \n", x[i]->num);
        x[i] = x[i]->next;
    }
}

void	sort(t_node *ary[], int ary_len)
{
    int i = 0;
    
    while (i < ary_len - 1)
    {
        if (ary[i]->num > ary[i + 1]->num)
        {
            printf("swap %d %d\n", ary[i]->num , ary[i + 1]->num);
            swap(ary, i, i + 1);
            i = 0;
            continue;
        }
        i++;
    }
}

void q_sort(t_node *x[], int left, int right, int n)
{
   int i, j;
   int pivot;

   i = left;
   j = right -1;
   pivot = x[(i + j) / 2]->num;
   printf("pivot %d\n", pivot);
   printf("i = %d\n", i);
   printf("j = %d\n", j);
   while (1)
	{
        while (x[i]->num < pivot)
        {
            i++;
            printf("x[i]->num = %d\n", x[i]->num);
        }
        while (pivot < x[i]->num)
        {
            j--;
            printf("x[j]->num = %d\n", x[j]->num);
        }
        printf("i = %d j = %d\n", i, j);
        if (i >= j)
			break;
		swap(x, i, j);
		i++;
		j--;
   }
   show_data(x, n);

   if (left < i - 1)
       q_sort(x, left, i - 1, n);
   if (j + 1 <  right)
       q_sort(x, j + 1, right, n);
}