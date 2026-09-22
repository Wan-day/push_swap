/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:33:55 by duk               #+#    #+#             */
/*   Updated: 2026/09/19 18:02:56 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
```
t_stack	*rmv_top(t_stack **s1)
{
	t_stack	*x;
	t_stack	*y;
	t_stack	*tmp;
	int		check;

	if ((*s1) == NULL)
		return (NULL);
	tmp = *s1;
	check = ((*s1)->next == (*s1));
	x = (*s1)->prev;
	y = (*s1)->next;
	x->next = y;
	y->prev = x;
	if (check == 1)
		*s1 = NULL;
	else
		*s1 = y;
	return (tmp);
}

static void	ins_top(t_stack *node, t_stack **s2)
{
	t_stack	*prev_node;

	if ((*s2) == NULL)
	{
		*s2 = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		prev_node = (*s2)->prev;
		node->next = (*s2);
		node->prev = prev_node;
		(*s2)->prev = node;
		prev_node->next = node;
		(*s2) = node;
	}
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	tmp = rmv_top(b);
	if (tmp == NULL)
		return ;
	ins_top (tmp, a);
	if (bench)
	{
		ft_printf("pa\n");
		bench->op_count[OP_PA]++;
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	tmp = rmv_top(a);
	if (tmp == NULL)
		return ;
	ins_top (tmp, b);
	if (bench)
	{
		ft_printf("pb\n");
		bench->op_count[OP_PB]++;
	}
}
```