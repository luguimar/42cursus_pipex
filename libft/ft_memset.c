/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:00:19 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/25 19:40:34 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t			i;
	unsigned char	*array;
	unsigned char	c1;

	array = dest;
	c1 = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		array[i] = c1;
		i++;
	}
	return (array);
}
