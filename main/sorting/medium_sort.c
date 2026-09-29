/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:09:19 by duk               #+#    #+#             */
/*   Updated: 2026/09/29 19:42:00 by duk              ###   ########.fr       */
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
	if (node->next == (*b))
		return (0);
	pos = 0;
	while (pos < size_b)
	{
		if (node->num > num && num > node->next->num)
			return (pos + 1);
		if ((node->num < node->next->num) && (node->num > num || num > node->next->num))
			return (pos + 1);
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

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	count;
	int	node_count;
	int	index;
	int	chunk;
	int min;
	int max;
	int chunk_count;
	int	size_b;
	int	num;
	int	pos;
	t_stack	*node;

	size_b = 0;
	chunk = 0;
	chunk_count = chunk_number(size);
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
	top_put(b, bench, size_b, (find_top(b)));
	while ((*b) != NULL)
		pa (a, b, bench);
}
