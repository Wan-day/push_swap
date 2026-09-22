#include "push_swap.h"

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

Complexity: O(nlogn) or log2(n) * (n + ~0.5n)
log2(n) comes from the the while (i < bits) loop. Bits is essentially log2(n).

n comes from the radix_check() function that always calls one of the
operations ra() or pb() and it goes over every single values in a.

~0.5n comes from the next loop while(*b), It roughly equals to the
half of the size of the stack a which are moved to the stack b.
So essentially for every pb() that happenes there will be a pa().
And pa() happens roughly half the time when sorting.
 */
void	complex_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	bits;
	int	max;
	int	i;
	int	j;

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
