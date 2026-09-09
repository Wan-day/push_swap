/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:54:07 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 14:54:08 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	size_of_s1;
	size_t	size_of_s2;
	size_t	i;

	i = 0;
	size_of_s1 = ft_strlen(s1);
	size_of_s2 = ft_strlen(s2);
	if (*s2 == '\0')
		return (ft_strdup(s1));
	else if (size_of_s1 >= (size_t)-1 - size_of_s2)
		return (NULL);
	result = malloc((size_of_s1 + size_of_s2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, size_of_s1 + 1);
	while (i < size_of_s2)
	{
		result[size_of_s1++] = s2[i];
		i++;
	}
	result[size_of_s1] = '\0';
	return (result);
}
