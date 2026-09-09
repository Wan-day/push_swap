/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:40:00 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:33:00 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char		test;
	const unsigned char	*str;
	size_t				len;

	len = ft_strlen(s);
	str = (const unsigned char *)s;
	test = (unsigned char)c;
	if (str[len] == test)
		return ((char *)&s[len]);
	if (len != 0)
		len--;
	while (len > 0)
	{
		if (str[len] == test)
			return ((char *)&s[len]);
		len--;
	}
	if (str[len] == test)
		return ((char *)&s[len]);
	return (NULL);
}
