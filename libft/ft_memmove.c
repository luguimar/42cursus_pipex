/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:41:09 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/26 09:06:05 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	d = dst;
	s = src;
	if (d <= s)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d = d + len;
		s = s + len;
		while (len--)
		{
			*(--d) = *(--s);
		}
	}
	return (dst);
}
/*{
	const char	*src1;
	char		*dest1;
	size_t		i;

	src1 = src;
	dest1 = dst;
	i = 0;
	if (dest1 <= src1)
		while (i < len)
		{
			dest1[i] = src1[i];
			i++;
		}
	else
	{
		src1 = src1 + len;
		dest1 = dest1 + len;
		i = len - 1;
		while (i > 0)
		{
			dest1[i] = src1[i];
			i--;
		}
	}
	return (dst);
}*/
