/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:38:19 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/03 14:30:15 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}
/*static char	*trimauxil(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	s1len;
	char	*str;

	i = ft_strlen(s1);
	s1len = i;
	j = 0;
	while (s1[i] >= 0)
	{
		if (s1[i] == set[j])
		{
			ft_memmove(ft_strchr(s1, set[j]), ft_strchr(s1, set[j]) + 1, s1len - i);
			j++;
			i = s1len + 1;

		}
		i--;
	}
	str = (char *) s1;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	s1len;
	char	*str;

	i = 0;
	j = 0;
	s1len = strlen(s1);
	s1 = trimauxil(s1, set);
	while (s1[i] != '\0')
	{
		if (s1[i] == set[j])
		{
			ft_memmove(ft_strchr(s1, set[j]), ft_strchr(s1, set[j]) + 1, s1len - i);
			j++;
			i = -1;

		}
		i++;
	}
	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	ft_memmove(str, s1, ft_strlen(s1) + 1);
	return (str);
}

#include <stdio.h>

int	main (int argc, char *argv[])
{
	if (argc == 3)
		printf("%s", ft_strtrim(argv[1], argv[2]));
	else
		printf("Numero de argumentos invalido");
}*/
