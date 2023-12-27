/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:20:17 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/26 15:30:48 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < len)
	{
		if (s1[i] != s2[i])
			return ((int)(unsigned char) s1[i] - (int)(unsigned char) s2[i]);
		i++;
	}
	if (i != len)
		return ((int)(unsigned char) s1[i] - (int)(unsigned char) s2[i]);
	return (0);
}
