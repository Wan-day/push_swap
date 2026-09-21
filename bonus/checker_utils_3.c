#include "bonus.h"

int	is_operation(char *temp, t_stack *a, t_stack *b, int count)
{
	if (strncmp("pa\n", temp) == 0)
		pa(a, b);
	else if (strncmp("pb\n", temp) == 0)
		pb(a, b);
	else if (strncmp("rra\n", temp) == 0)
		rra(a);
	else if (strncmp("rrb\n", temp) == 0)
		rrb(b);
	else if (strncmp("rrr\n", temp) == 0)
		rrr(a, b);
	else if (strncmp("ra\n", temp) == 0)
		ra(a);
	else if (strncmp("rb\n", temp) == 0)
		rb(b);
	else if (strncmp("rr\n", temp) == 0)
		rr(a, b);
	else if (strncmp("sa\n", temp) == 0)
		sa(a);
	else if (strncmp("sb\n", temp) == 0)
		sb(b);
	else if (strncmp("ss\n", temp) == 0)
		ss(a, b);
	else
		return (0);
	return (1);
}

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
