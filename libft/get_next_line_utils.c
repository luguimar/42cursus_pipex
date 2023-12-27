/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 03:40:49 by luguimar          #+#    #+#             */
/*   Updated: 2023/08/08 22:44:20 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchrnum(const char *s, int c)
{
	int		i;
	char	c1;

	i = 0;
	c1 = (char)c;
	if (c1 == '\0')
	{
		while (s[i] != c1)
			i++;
		return (i);
	}
	else
	{
		while (s[i] != c1 && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			return (-1);
	}
	return (i);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc((ft_strchrnum(s1, '\0') + ft_strchrnum(s2, '\0') + 1)
			* sizeof(char));
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
