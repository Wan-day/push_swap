double	calculate_disorder(t_stack *stack, int size)
{
	int	mistakes;
	int	total_pairs;
	int i;
	int j;

	i = 0;
	j = 0;
	total_pairs = 0;
	mistakes = 0;
	while (i < size)
	{
		while (j < size)
		{
			total_pairs += 1;
			if (stack->content > (stack->next)->content)
				mistakes += 1;
			stack = stack->next;
		}
	}
	return (mistakes / total_pairs);
}
