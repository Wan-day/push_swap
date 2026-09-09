/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:39:43 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 18:39:44 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dsize)
{
	size_t	i;
	size_t	size_of_dest;
	size_t	size_of_return;

	i = 0;
	size_of_dest = 0;
	while (size_of_dest < dsize && dest[size_of_dest])
		size_of_dest++;
	if (size_of_dest == dsize)
		return (dsize + ft_strlen(src));
	size_of_return = ft_strlen(src) + size_of_dest;
	while (src[i] && size_of_dest < dsize - 1)
	{
		dest[size_of_dest] = src[i];
		i++;
		size_of_dest++;
	}
	dest[size_of_dest] = '\0';
	return (size_of_return);
}
