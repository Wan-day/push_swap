/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:54:13 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 14:54:14 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	start_len;
	size_t	result_len;
	size_t	i;

	i = 0;
	if (ft_strlen(s) <= start)
		return (ft_calloc(1, sizeof(char)));
	start_len = ft_strlen(&s[start]);
	if (start_len > len)
		result_len = len;
	else
		result_len = start_len;
	result = malloc ((result_len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < result_len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
