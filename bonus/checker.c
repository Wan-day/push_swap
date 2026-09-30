/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:16:45 by dboldino          #+#    #+#             */
/*   Updated: 2026/09/30 16:28:42 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		count;
	char	*temp;

	if (argc < 2)
		return (0);
	a = load_stack(argc, argv, &count);
	b = NULL;
	if (a == NULL)
		return (0);
	temp = get_next_line(0);
	while (temp != NULL)
	{
		do_operation(temp, &a, &b);
		temp = get_next_line(0);
	}
	if (is_sorted(a, count))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(&a);
	free_stack(&b);
	return (0);
}
