/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 13:25:12 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/08 16:12:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	module(int n)
{
	long int	i;

	if (n < 0)
		i = - (long int) n;
	else
		i = (long int) n;
	return (i);
}

int	algcounter(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*isneg(int algcount, int n)
{
	int		i;
	char	*nbr;

	nbr = malloc((algcount + 2) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[0] = '-';
	nbr[algcount + 1] = '\0';
	i = algcount;
	while (i > 0)
	{
		nbr[i] = (char)(module(n) % 10L + '0');
		n = n / 10;
		i--;
	}
	return (nbr);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		algcount;
	int		i;

	algcount = algcounter(n);
	if (n >= 0)
	{
		nbr = malloc((algcount + 1) * sizeof(char));
		if (!nbr)
			return (NULL);
		nbr[algcount] = '\0';
		i = algcount - 1;
		while (i >= 0)
		{
			nbr[i] = (char)(n % 10 + '0');
			n = n / 10;
			i--;
		}
	}
	else
		nbr = isneg(algcount, n);
	return (nbr);
}
/*
#include <stdio.h>
int	main(int argc, char *argv[])
{
	int	n;
	char	*str;

	if (argc == 2)
	{
		n = ft_atoi(argv[1]);
		str = ft_itoa(n);
		printf("%s", str);
	}
	else
		printf("numero invalido de argumentos");
}*/
