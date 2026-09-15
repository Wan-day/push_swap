/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:33:16 by duk               #+#    #+#             */
/*   Updated: 2026/09/15 13:36:15 by duk              ###   ########.fr       */
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
