/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:54:00 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/27 10:48:38 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	*b1;

	c1 = (unsigned char)c;
	b1 = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		if (b1[i] == c1)
			return (b1 + i);
		i++;
	}
	return (NULL);
}
