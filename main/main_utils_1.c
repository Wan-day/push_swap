#include "push_swap.h"

/*
Allocates a node alone in its own circular list (it points to itself).
Returns NULL if the allocation fails.
*/
static t_stack	*stack_new(int content)
{
	t_stack	*res;

	res = ft_calloc(1, sizeof(t_stack));
	if (res == NULL)
		return (NULL);
	res->num = content;
	res->next = res;
	res->prev = res;
	return (res);
}

/*
Adds a node holding content at the bottom of the stack: between the
current last node (stack->prev) and the head. Returns 0 if the
allocation fails, 1 otherwise.
*/
static int	stack_add(int content, t_stack *stack)
{
	t_stack	*node;
	t_stack	*last;

	node = stack_new(content);
	if (node == NULL)
		return (0);
	last = stack->prev;
	last->next = node;
	node->prev = last;
	node->next = stack;
	stack->prev = node;
	return (1);
}

/*
Builds stack a from the array of count numbers (count >= 1). The first
number is the top of the stack, as the subject requires. If an
allocation fails, frees the stack built so far and nums, then exits
with "Error". On success nums is not freed: it still belongs to the
caller.
*/
t_stack	*build_stack(int *nums, int count)
{
	t_stack	*head;
	int		i;

	head = stack_new(nums[0]);
	if (head == NULL)
	{
		free(nums);
		put_error();
	}
	i = 1;
	while (i < count)
	{
		if (!stack_add(nums[i], head))
		{
			free(nums);
			free_stack(&head);
			put_error();
		}
		i++;
	}
	return (head);
}

/*
Reads argv completely: options, numbers, validation, and builds stack a.
*count receives the number of elements. Returns NULL (with nothing to
free) if argv holds no number. Temporary arrays are freed here.
*/
t_stack	*load_stack(int argc, char **argv, t_options *opts, int *count)
{
	char	**tokens;
	int		*nums;
	t_stack	*head;

	tokens = extract_options(argc, argv, opts);
	if (tokens[0] == NULL)
	{
		free(tokens);
		return (NULL);
	}
	nums = parse_tokens(tokens, count);
	free(tokens);
	head = build_stack(nums, *count);
	free(nums);
	return (head);
}
