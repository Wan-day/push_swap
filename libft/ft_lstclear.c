/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 17:59:18 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:00:52 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;
	t_list	*next;

	if (lst == NULL || *lst == NULL)
		return ;
	prev = *lst;
	while (prev != NULL)
	{
		next = prev->next;
		ft_lstdelone(prev, del);
		prev = next;
	}
	*lst = NULL;
}
