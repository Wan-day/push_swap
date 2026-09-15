int	is_number(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (ft_is_digit(*str))
			str++;
		else
			return (0);
	}
	return (1)
}

int	*parse_tokens(char **tokens, int remaining, int *count)
{
	int		*result;
	int		i;
	char	**split_tokens;
	
	split_tokens = ft_split(tokens, ' ');
	if (split_tokens == NULL)
		put_error();
	*count = 0;
	while (split_tokens[*count] != NULL)
		(*count)++;
	result = ft_calloc(*count + 1, sizeof(int));
	if (result == NULL)
		put_error();
	i = 0;
	while (i < *count)
	{
		if (is_number(tokens[i]))
		{
			result[i] = ft_atoi(tokens[i]);
		}
		else
			put_error();
	}
	return (result);
}

t_stack	*stack_new(int content)
{
	t_stack	*res;

	res = ft_calloc(1, sizeof(t_stack));
	if (res == NULL)
		put_error();
	res->num = content;
	return (res);
}

void	stack_add(int content, t_stack *stack)
{
	t_stack	*new;
	t_stack	*temp;

	new = stack_new(content);
	temp = stack->prev;
	temp->next = *new;
	new->prev = *temp;
	new->next = *stack;
	stack->prev = *new;
}

t_stack	*build_stack(int *tokens, int count, t_bench *bench)
{
	t_stack	*result;
	int		i;
	double	disorder;

	i = 0;
	result = stack_new(tokens[i]);
	i++;
	while (i < count)
		stack_add(tokens[i], result);
	disorder = calculate_disorder(result, count);
	bench->disorder = disorder;
	return (result);
}
