#include "push_swap.h"

/*
Counts the mistakes of one node: how many of the `remaining` nodes that
follow it are smaller than it. The count is given instead of looking for
a NULL because the list is circular.
*/
static int	count_mistakes_from(t_stack *node, int remaining)
{
	int		mistakes;
	t_stack	*cursor;

	mistakes = 0;
	cursor = node->next;
	while (remaining > 0)
	{
		if (node->num > cursor->num)
			mistakes++;
		cursor = cursor->next;
		remaining--;
	}
	return (mistakes);
}

/*
Disorder of the stack: mistakes / total pairs, where a mistake is a pair
(i, j) with i before j and a[i] > a[j]. Returns 0.0 for a sorted stack
and 1.0 for a reversed one. Stacks with less than 2 elements are sorted.
The counters are long: the number of pairs grows with size squared.
*/
double	calculate_disorder(t_stack *a, int size)
{
	int		i;
	long	mistakes;
	long	total_pairs;
	t_stack	*node;

	if (!a || size < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = (long)size * (size - 1) / 2;
	node = a;
	i = 0;
	while (i < size)
	{
		mistakes += count_mistakes_from(node, size - i - 1);
		node = node->next;
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}

/*
Returns 1 if the stack is sorted in ascending order from the head, 0
otherwise. Only size - 1 neighbours are compared: comparing the last
node with the head (which is its next) would wrongly report a mistake.
*/
int	is_sorted(t_stack *a, int size)
{
	int		i;
	t_stack	*node;

	if (!a || size < 2)
		return (1);
	node = a;
	i = 0;
	while (i < size - 1)
	{
		if (node->num > node->next->num)
			return (0);
		node = node->next;
		i++;
	}
	return (1);
}

/*
Looks at the strategy selected by the user and calls the selected algorithm.
If --adaptive flag was chose then it selects the algorithm based on the
disorder of the stack.
When the stack is almost sorted (disorder > 0.2) it calls the simple algorithm.
When the stack is somewhat sorther (0.2 >= discorder > 0.5) it calls the 
medium algorithm.
When the stack is not sorted (disorder <= 0.5) it calls the complex algorithm.
*/
void	sort_stack(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	if (bench->strategy == SIMPLE)
		simple_sort(a, b, bench, size);
	else if (bench->strategy == MEDIUM)
		medium_sort(a, b, bench, size);
	else if (bench->strategy == COMPLEX)
		complex_sort(a, b, bench, size);
	else if (bench->strategy == ADAPTIVE)
	{
		if (bench->disorder < 0.2)
			simple_sort(a, b, bench, size);
		else if(bench->disorder >= 0.2 && bench->disorder < 0.5)
			medium_sort(a, b, bench, size);
		else 
			complex_sort(a, b, bench, size);
	}
}
