/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:54:03 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:05:30 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len_s1;
	char	*result;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	while (i < len_s1 && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (len_s1 > i && ft_strchr(set, s1[len_s1 - 1]) != NULL)
		len_s1--;
	result = malloc((len_s1 - i + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len_s1)
	{
		result[j] = s1[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}
