/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 00:29:34 by duk               #+#    #+#             */
/*   Updated: 2026/09/22 17:53:44 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
the scan_min function runs through the stack a
and finding the min value containing nodes and
returning their position as int
*/

int	scan_min(t_stack **a)
{
	t_stack	*node;
	int		pos_min;
	int		pos;
	int		min;

	node = (*a);
	min = (*a)->num;
	pos_min = 0;
	pos = 0;
	while (node->next != (*a))
	{
		node = node->next;
		pos++;
		if (node->num < min)
		{
			min = node->num;
			pos_min = pos;
		}
	}
	return (pos_min);
}

/*
rotates the stack a backward or forward depending on 
where the min value is located that has been denoted as pos_min, 
as the circular linked list has no NULL thus rotating backward or
forward which ever is closer will be used.
*/

void	put_top(t_stack **a, t_bench *bench, int len, int pos_min)
{
	int	count;

	count = 0;
	if (pos_min <= len - pos_min)
	{
		while (count < pos_min)
		{
			ra(a, bench);
			count++;
		}
	}
	else
	{
		while (count < len - pos_min)
		{
			rra(a, bench);
			count++;
		}
	}
}

/*
the sorting function works by scaning the stack a to
find the min value, and afterwards rotates it to the
head of stack a and pushes is to stack b, 
*/

void	simple_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	pos_min;

	while (size > 0)
	{
		pos_min = scan_min(a);
		put_top(a, bench, size, pos_min);
		pb(a, b, bench);
		size--;
	}
	while ((*b) != NULL)
	{
		pa(a, b, bench);
	}
}
