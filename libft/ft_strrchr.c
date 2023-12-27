/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:34:21 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/26 15:16:00 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c1;
	char	*pointer;

	pointer = (char *) s;
	i = ft_strlen(s);
	c1 = (char) c;
	if (i == 0 && c1 != '\0')
		return (NULL);
	if (c1 == '\0')
		return (pointer + ft_strlen(s));
	else
	{
		while (s[i] != c1 && i >= 0)
			i--;
		if (i < 0)
			return (NULL);
	}
	return (pointer + ft_strlen(s) - (ft_strlen(s) - i));
}
