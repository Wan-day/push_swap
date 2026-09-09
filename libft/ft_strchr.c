/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 18:39:37 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:04:53 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char		test;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	test = (unsigned char)c;
	while (*str)
	{
		if (*str == test)
			return ((char *)s);
		str++;
		s++;
	}
	if (*str == test)
		return ((char *)s);
	else
		return (NULL);
}
