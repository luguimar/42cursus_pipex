/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 04:10:04 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/26 08:53:26 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	const char	*src1;
	char		*dest1;
	size_t		i;

	if (!dst && !src)
		return (NULL);
	src1 = src;
	dest1 = dst;
	i = 0;
	while (i < len)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dst);
}
