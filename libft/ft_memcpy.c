/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboldino <dboldino@student.42prague.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 17:19:58 by dboldino          #+#    #+#             */
/*   Updated: 2026/08/24 19:32:16 by dboldino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;

	p_src = (const unsigned char *)src;
	p_dest = (unsigned char *)dest;
	while (n--)
	{
		*p_dest = *p_src;
		p_dest++;
		p_src++;
	}
	return (dest);
}
