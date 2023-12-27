/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:04:30 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/26 10:13:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	lenghts;

	i = 0;
	lenghts = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dest_len)
		lenghts = dest_len + src_len;
	else
		lenghts = src_len + dstsize;
	while (src[i] != '\0' && (dest_len + 1) < dstsize)
	{
		dst[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dst[dest_len] = '\0';
	return (lenghts);
}
