/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:39:35 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/05 18:07:10 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	uporlo(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = ft_toupper(*c);
	else
		*c = ft_tolower(*c);
}

#include <stdio.h>

int	main(int argc, char *argv[])
{
	char	*str;
	if (argc == 2)
	{
		str = argv[1];
		ft_striteri(argv[1], uporlo);
		printf("%s", str);
	}
	else
		printf("numero invalido de argumentos");
	return (0);
}*/
