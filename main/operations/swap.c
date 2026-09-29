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

#include "push_swap.h"

void	sa(t_stack **a, t_bench *bench)
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
	if (bench)
	{
		ft_printf("sa\n");
		bench->op_count[OP_SA]++;
	}
}

void	sb(t_stack **b, t_bench *bench)
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
	if (bench)
	{
		ft_printf("sb\n");
		bench->op_count[OP_SB]++;
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa(a, NULL);
	sb(b, NULL);
	if (bench)
	{
		ft_printf("ss\n");
		bench->op_count[OP_SS]++;
	}
}
