/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:17:25 by dboldino          #+#    #+#             */
/*   Updated: 2026/09/30 16:23:02 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Prints name followed by the number value on stderr, without newline. */
void	put_field(char *name, int value)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(value, 2);
}

/*
Prints the disorder as a percentage with 2 decimals ("49.99%").
The value is rounded to hundredths of a percent and printed with
integers only.
*/
void	print_disorder(double disorder)
{
	int	hundredths;

	hundredths = (int)(disorder * 10000.0 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(hundredths / 100, 2);
	ft_putchar_fd('.', 2);
	if (hundredths % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(hundredths % 100, 2);
	ft_putendl_fd("%", 2);
}

/* Returns the display name of a strategy. */
char	*strategy_name(int strategy)
{
	if (strategy == SIMPLE)
		return ("Simple / O(n^2)");
	if (strategy == MEDIUM)
		return ("Medium / O(n sqrt(n))");
	if (strategy == COMPLEX)
		return ("Complex / O(n log n)");
	return ("Adaptive");
}

/* Prints the two lines with the number of times each operation was used. */
void	print_op_lines(t_bench *bench)
{
	ft_putstr_fd("[bench] ", 2);
	put_field("sa: ", bench->op_count[OP_SA]);
	put_field(" sb: ", bench->op_count[OP_SB]);
	put_field(" ss: ", bench->op_count[OP_SS]);
	put_field(" pa: ", bench->op_count[OP_PA]);
	put_field(" pb: ", bench->op_count[OP_PB]);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	put_field("ra: ", bench->op_count[OP_RA]);
	put_field(" rb: ", bench->op_count[OP_RB]);
	put_field(" rr: ", bench->op_count[OP_RR]);
	put_field(" rra: ", bench->op_count[OP_RRA]);
	put_field(" rrb: ", bench->op_count[OP_RRB]);
	put_field(" rrr: ", bench->op_count[OP_RRR]);
	ft_putchar_fd('\n', 2);
}

/* Calculates the total operations done by the algorithm */
void	bench_total(t_bench *bench)
{
	int	i;

	i = 0;
	while (i < OP_COUNT)
	{
		bench->total_ops += bench->op_count[i];
		i++;
	}
}
