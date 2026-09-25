/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:35:15 by duk               #+#    #+#             */
/*   Updated: 2026/09/15 13:36:02 by duk              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_bench *bench)
{
	if ((*a) == NULL || (*a)->next == (*a))
		return ;
	(*a) = (*a)->next;
	if (bench)
	{
		ft_printf("ra\n");
		bench->op_count[OP_RA]++;
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	if ((*b) == NULL || (*b)->next == (*b))
		return ;
	(*b) = (*b)->next;
	if (bench)
	{
		ft_printf("rb\n");
		bench->op_count[OP_RB]++;
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra(a, NULL);
	rb(b, NULL);
	if (bench)
	{
		ft_printf("rr\n");
		bench->op_count[OP_RR]++;
	}
}
