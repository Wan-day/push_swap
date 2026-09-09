/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:39:56 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 18:39:57 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_little;
	size_t	len_big;

	i = 0;
	len_little = ft_strlen(little);
	len_big = ft_strlen(big);
	if (*little == '\0')
		return ((char *)big);
	if (len_little > len_big)
		return (NULL);
	while (i + len_little <= len && i + len_little <= len_big)
	{
		if (ft_strncmp(&big[i], little, len_little) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
