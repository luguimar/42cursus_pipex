/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:13:58 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/05 17:37:24 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*str;

	i = 0;
	len = ft_strlen(s);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char	uporlo(unsigned int i, char c)
{
	if (i % 2 == 0)
		c = ft_toupper(c);
	else
		c = ft_tolower(c);
	return (c);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	if (argc == 2)
	{
		str = ft_strmapi(argv[1], uporlo);
		printf("%s", str);
		free(str);
	}
	else
		printf("numero invalido de argumentos");
	return (0);
}*/
