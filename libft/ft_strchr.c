/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:04:18 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/26 13:32:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c1;
	char	*pointer;

	pointer = (char *) s;
	i = 0;
	c1 = (char) c;
	if (c1 == '\0')
	{
		while (s[i] != c1)
			i++;
		return (pointer + i);
	}
	else
	{
		while (s[i] != c1 && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (NULL);
	}
	return (pointer + i);
}
