/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:29:36 by duk               #+#    #+#             */
/*   Updated: 2026/09/16 13:47:36 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sa(t_stack **a)
{
	t_stack	*node1;
	t_stack	*node2;
	int		tmp;

	if ((*a) == NULL || (*a)->next == (*a))
		return ;
	node1 = *a;
	node2 = (*a)->next;
	tmp = node1->num;
	node1->num = node2->num;
	node2->num = tmp;
}

void	sb(t_stack **b)
{
	t_stack	*node1;
	t_stack	*node2;
	int		tmp;

	if ((*b) == NULL || (*b)->next == (*b))
		return ;
	node1 = *b;
	node2 = (*b)->next;
	tmp = node1->num;
	node1->num = node2->num;
	node2->num = tmp;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}

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
	if (check == 0)
		*s1 = y;
	else
		*s1 = NULL;
	return (tmp);
}

void	ins_top(t_stack *node, t_stack **s2)
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

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = rmv_top(b);
	if (tmp == NULL)
		return ;
	ins_top (tmp, a);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = rmv_top(a);
	if (tmp == NULL)
		return ;
	ins_top (tmp, b);
}

void	ra(t_stack **a)
{
	if ((*a) == NULL || (*a)->next == (*a))
		return ;
	(*a) = (*a)->next;
}

void	rb(t_stack **b)
{
	if ((*b) == NULL || (*b)->next == (*b))
		return ;
	(*b) = (*b)->next;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rra(t_stack **a)
{
	if ((*a) == NULL || (*a)->next == (*a))
		return ;
	(*a) = (*a)->prev;
}

void	rrb(t_stack **b)
{
	if ((*b) == NULL || (*b)->next == (*b))
		return ;
	(*b) = (*b)->prev;
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}
