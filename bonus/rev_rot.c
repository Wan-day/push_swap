/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duk <duk@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 13:36:25 by duk               #+#    #+#             */
/*   Updated: 2026/09/30 16:17:07 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
