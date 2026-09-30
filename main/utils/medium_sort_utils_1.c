/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort_utils_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 15:42:16 by duk               #+#    #+#             */
/*   Updated: 2026/09/30 15:59:36 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
provides and rounds us the number of
chunks the stack a size divide into.
*/

int	chunk_number(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
		i++;
	return (i);
}

/*
rotates b to have the pos at the top, depending on 
how far the position is from the size of stack b
*/

void	top_put(t_stack **b, t_bench *bench, int size_b, int pos)
{
	if (pos > size_b - pos)
		pos = pos - size_b;
	while (pos > 0)
	{
		rb(b, bench);
		pos--;
	}
	while (pos < 0)
	{
		rrb(b, bench);
		pos++;
	}
}

/*
identifies the maximum and minimum value in the stack a,
by setting the head value as the min and max and comparing
the rest to update the min and max until all the values are
gone over
*/

void	min_max(t_stack **a, int *min, int *max)
{
	t_stack	*node;

	if ((*a) == NULL)
		return ;
	*min = (*a)->num;
	*max = (*a)->num;
	node = (*a)->next;
	while (node != (*a))
	{
		if (node->num < *min)
			*min = node->num;
		if (node->num > *max)
			*max = node->num;
		node = node->next;
	}
}

/*
finds the current max value and returns it's
position in stack b, the 
*/

int	find_top(t_stack **b)
{
	t_stack	*node;
	int		pos_max;
	int		pos;
	int		max;

	if ((*b) == NULL)
		return (0);
	node = (*b);
	max = (*b)->num;
	pos_max = 0;
	pos = 0;
	while (node->next != (*b))
	{
		node = node->next;
		pos++;
		if (node->num > max)
		{
			max = node->num;
			pos_max = pos;
		}
	}
	return (pos_max);
}

/*
function designed to count and return the size
of a stack, by going through all the elements while
keeping seperate size variable running
*/

int	count_size(t_stack **b)
{
	t_stack	*node;
	int		size;

	if ((*b) == NULL)
		return (0);
	size = 1;
	node = (*b)->next;
	while (node != (*b))
	{
		node = node->next;
		size++;
	}
	return (size);
}
