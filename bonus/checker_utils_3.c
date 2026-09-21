#include "bonus.h"

static int	op_test(char *temp, t_stack **a, t_stack **b)
{
	if (ft_strncmp(temp, "pa", 3) == 0)
		pa(a, b);
	else if (ft_strncmp(temp, "pb", 3) == 0)
		pb(a, b);
	else if (ft_strncmp(temp, "rra", 4) == 0)
		rra(a);
	else if (ft_strncmp(temp, "rrb", 4) == 0)
		rrb(b);
	else if (ft_strncmp(temp, "rrr", 4) == 0)
		rrr(a, b);
	else if (ft_strncmp(temp, "ra", 3) == 0)
		ra(a);
	else if (ft_strncmp(temp, "rb", 3) == 0)
		rb(b);
	else if (ft_strncmp(temp, "rr", 3) == 0)
		rr(a, b);
	else if (ft_strncmp(temp, "sa", 3) == 0)
		sa(a);
	else if (ft_strncmp(temp, "sb", 3) == 0)
		sb(b);
	else if (ft_strncmp(temp, "ss", 3) == 0)
		ss(a, b);
	else
		return (0);
	return (1);
}

int	is_operation(char *temp, t_stack **a, t_stack **b)
{
	size_t	len;
	int		test;

	len = ft_strlen(temp);
	if (len > 0 && temp[len - 1] == '\n')
		temp[len - 1] = '\0';
	test = op_test(temp, a, b);
	return (test);
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
