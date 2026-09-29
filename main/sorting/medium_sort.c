/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:09:19 by duk               #+#    #+#             */
/*   Updated: 2026/09/29 15:33:52 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
ins_pos finds the position where num can be placed in stack b,
the main reason is to have the stack b sorted decending
*/
int	find_pos(t_stack **b, int size_b, int num)
{
	t_stack	*node;
	int		pos;
	
	if ((*b) == NULL)
		return (0);
	node = (*b);
	pos = 0;
	while (pos < size_b)
	{
		if (node->num < num)
			return (pos);
		node = node->next;
		pos++;
	}
	return (size_b);
}

/*
divides the chunk based on stack a's size as root of n
*/

int	chunk_number(int size)
{
	int	i;

	i = 1;
	while (i * i < size)
	{
		i++;
	}
	return (i);
}

void	top_put(t_stack **b, t_bench *bench, int size_b, int pos_min)
{
	int	count;

	count = 0;
	if (pos_min <= size_b - pos_min)
	{
		while (count < pos_min)
		{
			rb(b, bench);
			count++;
		}
	}
	else
	{
		while (count < size_b - pos_min)
		{
			rrb(b, bench);
			count++;
		}
	}
}

void	min_max(t_stack **a, int *min, int*max)
{
	t_stack *node;

	if ((*a) == NULL)
		return ;
	node = (*a);
	*min = node->num;
	*max = node->num;
	node = node->next;
	while (node != (*a))
	{
		if (node->num < *min)
			*min = node->num;
		if (node->num > *max)
			*max = node->num;
		node = node->next;
	}
}

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	count;
	int	node_count;
	int	index;

	chunk = 0;
	min_max(a, &min, &max);
	while (chunk < chunk_count)
	{
		count = 0;
		node_count = size - size_b;
		while (count < node_count)
		{
			node = (*a);
			num = node->num;
			index = chunk_count * ((double)num - min) / (max - min);
			if (index == chunk_count)
				index = chunk_count - 1;
			if (chunk == index)
			{
				pos = find_pos(b, size_b, num);
				top_put(b, bench, size_b, pos);
				pb (a, b, bench);
				size_b++;
			}
			else
				ra(a, bench);
			count++;
		}
		chunk++;
	}
}
