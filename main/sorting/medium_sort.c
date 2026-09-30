/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 13:09:19 by duk               #+#    #+#             */
/*   Updated: 2026/09/30 15:59:40 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
find_pos function finds the position where num fits and returns that 
position + 1 because it respects the numbers before it 
(how many numbers before the spot),
additionally it covers cases where stack b is empty or there is 1 num.
the num is found in stack b by comapring the 2 neighbors or at the edge of
stack b where the biggest number and smallest number meets in stack b.
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
		if ((node->num < node->next->num)
			&& (node->num > num || num > node->next->num))
			return (pos + 1);
		node = node->next;
		pos++;
	}
	return (size_b);
}

/*
only the head value in stack a is checked and pushed to stack
b in its sorted position, if any value in stack a that
are not within the chunk_limit the value is sent to the bottom
*/

static void	p_chunk(t_stack **a, t_stack **b, t_bench *bench, int chunk_limit)
{
	int	count;
	int	size_b;

	count = count_size(a);
	while (count > 0)
	{
		if ((*a)->num <= chunk_limit)
		{
			size_b = count_size(b);
			top_put(b, bench, size_b, find_pos(b, size_b, (*a)->num));
			pb (a, b, bench);
		}
		else
			ra (a, bench);
		count--;
	}
}

/*
the function sorts stack a into stack b chunk by chunk,
afterwards moves it back to a.

the numbers from min to max are cut into chunk_count equal slices.
chunk_limit is the highest number of the current chunk (the last
chunk ends on the highest value), for each chunk, p_chunk moves its numbers
from a to b. b is kept in order (biggest on top), so each number
goes to its own spot in b, which later will be rotated
to push in the values from a.

when a is empty, b is rotated so its max is on top, then every
number is pushed back to a, biggest first, so a ends up sorted.
*/

void	medium_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	min;
	int	max;
	int	chunk_limit;
	int	chunk_count;
	int	chunk_pos;

	min_max(a, &min, &max);
	chunk_count = chunk_number(size);
	chunk_pos = 0;
	while (chunk_pos < chunk_count)
	{
		chunk_limit = min + (max - min) * (chunk_pos +1) / chunk_count;
		p_chunk(a, b, bench, chunk_limit);
		chunk_pos++;
	}
	top_put(b, bench, count_size(b), (find_top(b)));
	while ((*b) != NULL)
		pa (a, b, bench);
}
