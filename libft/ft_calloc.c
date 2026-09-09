/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:39:15 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:01:53 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*result;
	size_t			i;
	size_t			len;

	i = 0;
	if (size != 0 && n > (size_t)-1 / size)
		return (NULL);
	len = n * size;
	result = malloc(len);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
