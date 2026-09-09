/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:12:44 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:01:22 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;
	void	*changed_content;

	result = NULL;
	if (f && del)
	{
		while (lst != NULL)
		{
			changed_content = f(lst->content);
			temp = ft_lstnew(changed_content);
			if (temp == NULL)
			{
				del(changed_content);
				ft_lstclear(&result, del);
				return (NULL);
			}
			ft_lstadd_back(&result, temp);
			lst = lst->next;
		}
	}
	return (result);
}
