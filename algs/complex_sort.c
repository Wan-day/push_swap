#include "push_swap.h"

/*
Assigns a zero-based rank to every node. The rank represents how many 
values in teh stack are smaller than this value.
*/
static void assign_ranks(t_stack **a, int size)
{
	int		i;
	int 	j;
	t_stack *temp_main;
	t_stack *temp;

	i = 0;
	temp_main = *a;
	while (i < size)
	{
		j = 0;
		temp_main->rank = 0;
		temp = temp_main;
		while (j < size)
		{
			if (temp_main->value > temp->value)
				temp_main->rank++;
			temp = temp->next;
			j++;
		}
		temp_main = temp_main->next;
	}
}

/*
Compare the current value of i-th bit of the value a to 1 and either move it 
to the stack b or go to the next value in the stack a.
*/
static void	radix_check(t_stack **a, t_stack **b, t_bench *bench, int i)
{
	if (((*a)->rank >> i) & 1)
		ra(a, bench);
	else
		pb(a, b, bench);
}

/*
Sort the stack a using the LSD binary radix sort.

First values are converted to ranks so that elements are represented byt a non
negative int from 0 to size - 1.

'bits' determents how many bits are needed to represent the highest rank.

For reach bit it calls the radix_check() function and then
collapses the stack b into the stack a which preserves the ordering.
 */
void	complex_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int bits;
	int max;
	int i;
	int j;

	assign_ranks(a, size);
	max = size - 1;
	bits = 0;
	while (max > 0)
	{
		bits++;
		max >>= 1;
	}
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			radix_check(a, b, bench, i);
			j++;
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}
