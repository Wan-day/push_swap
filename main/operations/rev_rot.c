/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:36:25 by duk               #+#    #+#             */
/*   Updated: 2026/09/15 13:36:51 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_bench *bench)
{
	if ((*a) == NULL || (*a)->next == (*a))
		return ;
	(*a) = (*a)->prev;
	if (bench)
	{
		ft_printf("rra\n");
		bench->op_count[OP_RRA]++;
	}
}

void	rrb(t_stack **b, t_bench *bench)
{
	if ((*b) == NULL || (*b)->next == (*b))
		return ;
	(*b) = (*b)->prev;
	if (bench)
	{
		ft_printf("rrb\n");
		bench->op_count[OP_RRB]++;
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rra(a, NULL);
	rrb(b, NULL);
	if (bench)
	{
		ft_printf("rrr\n");
		bench->op_count[OP_RRR]++;
	}
}
