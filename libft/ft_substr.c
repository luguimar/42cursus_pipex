/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:20:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/15 01:54:39 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	strlength;
	char	*str;

	i = start;
	strlength = 0;
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		*str = '\0';
		return (str);
	}
	while (s[i] != '\0' && strlength < len)
	{
		i++;
		strlength++;
	}
	str = malloc(sizeof(char) * strlength + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, strlength + 1);
	return (str);
}
