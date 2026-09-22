/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/18 00:29:34 by duk               #+#    #+#             */
/*   Updated: 2026/09/22 12:05:47 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rotates the stack a backward or forward depending on 
where the min value is located that has been denoted as pos_min, 
as the circular linked list has no NULL thus rotating backward or
forward which ever is closer will be used.
*/
static void	put_top(t_stack **a, int len, int pos_min, t_bench *bench)
{
	int	count;

	count = 0;
	if (pos_min < len - pos_min)
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
copies the stack a numbers into the temporary array. 
*/
static void	cpy_list(t_stack **a, int *tmp_array)
{
	int		i;
	t_stack	*node;

	node = *a;
	i = 1;
	tmp_array[0] = (*a)->num;
	while (node->next != *a)
	{
		node = node->next;
		tmp_array[i] = node->num;
		i++;
	}
}

/*
scans the array to find the position of the minimum
value and returns the position as pos_min.
*/
static int	scan_min(int *tmp_array, int len)
{
	int	min;
	int	i;
	int	pos_min;

	i = 1;
	min = tmp_array[0];
	pos_min = 0;
	while (len > i)
	{
		if (tmp_array[i] < min)
		{
			min = tmp_array[i];
			pos_min = i;
		}
		i++;
	}
	return (pos_min);
}

/*
cleans the array after where min value is
removed and the numbers on the right moves to the right
side of the array, and readjusts the lenght of the array.
*/
static int	shift_elem(int *tmp_array, int len, int pos_min)
{
	int	i;

	i = 0;
	while (len - 1 - pos_min > i)
	{
		tmp_array[pos_min + i] = tmp_array[pos_min + i + 1];
		i++;
	}
	len = len - 1;
	return (len);
}

/*
allocates memory to the array and copies the num
from stack a to the array and until the each elemet in
the array is scanned and gets that min value to the top of
stack a and pushed to the head of stack b until all the elements
are sorted in b, which then frees the array
and pushes the elements to stack a.
*/
void	simple_sort(t_stack **a, t_stack **b, t_bench *bench, int size)
{
	int	pos_min;
	int	len;
	int	*tmp_array;

	len = size;
	tmp_array = ft_calloc (len, sizeof(int));
	if (tmp_array == NULL)
	{
		free_stack(a);
		put_error();
	}
	cpy_list(a, tmp_array);
	while (len > 0)
	{
		pos_min = scan_min(tmp_array, len);
		put_top(a, len, pos_min, bench);
		pb(a, b, bench);
		len = shift_elem(tmp_array, len, pos_min);
	}
	free(tmp_array);
	while ((*b) != NULL)
	{
		pa(a, b, bench);
	}
}
