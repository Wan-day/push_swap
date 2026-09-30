/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 16:17:00 by dboldino          #+#    #+#             */
/*   Updated: 2026/09/30 16:17:01 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

/* Prints "Error" on stderr and exits with status 1. */
void	put_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

/* Frees a NULL terminated array of strings, such as the result of ft_split. */
void	free_split(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

/*
Frees every node of a circular stack and sets *stack to NULL. The circle
is opened first (last->next = NULL) so the list can be walked to its
end. Does nothing on an empty stack.
*/
void	free_stack(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	if (stack == NULL || *stack == NULL)
		return ;
	(*stack)->prev->next = NULL;
	node = *stack;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
	*stack = NULL;
}
