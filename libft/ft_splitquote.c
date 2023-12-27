/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 20:46:24 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/04 15:46:13 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(char *s, char c)
{
	int	wordcount;
	int	i;

	if (!s)
		return (0);
	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (is_end_wordquote(s, i, c))
			wordcount++;
		i++;
	}
	return (wordcount);
}

static void	wordfiller(char *j, char *str, char c)
{
	int	i;

	i = 0;
	while (inquote(j, i) || (!quote(j, i) && j[i] != c && j[i] != '\0'))
	{
		str[i] = j[i];
		i++;
	}
	str[i] = '\0';
}

static void	strfiller(char *s, char **str, char c)
{
	int	i;
	int	j;
	int	k;
	int	nextc;

	i = 0;
	k = 0;
	nextc = 0;
	while (s[i] != '\0')
	{
		if (is_end_wordquote(s, i, c))
		{
			j = i + 1;
			while (j-- >= nextc)
			{
				if (is_beginning_wordquote(s, j, c))
				{
					nextc = j + 1;
					wordfiller(s + j, str[k], c);
					k++;
				}
			}
		}
		i++;
	}
}

static void	strmalloc(int *j, char ***str, int *k)
{
	(*str)[*k] = malloc((*j + 1) * sizeof(char));
	if (!(*str)[*k])
	{
		while (*k > 0)
		{
			*k = (*k) - 1;
			free((void *)(*str)[*k]);
			(*str)[*k] = NULL;
		}
		free(*str);
		*str = NULL;
	}
	*k = (*k) + 1;
	*j = 0;
}

char	**ft_splitquote(char *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = -1;
	j = 1;
	k = 0;
	str = malloc((wordcounter(s, c) + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	str[wordcounter(s, c)] = NULL;
	while (s[++i] != '\0')
	{
		if (is_end_wordquote(s, i, c))
		{
			strmalloc(&j, &str, &k);
			if (!str)
				return (NULL);
		}
		if (inquote(s, i) || (!quote(s, i) && s[i] != c))
			j++;
	}
	strfiller((char *)s, str, c);
	return (str);
}
/*
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		char **result = ft_split(argv[1], argv[2][0]);
		if (result)
		{
			while (result[i] != NULL)
			{
				printf("%s$\n", result[i]);
				i++;
			}
			i = 0;
			while (result[i] != NULL)
			{
				free(result[i]);
				i++;
			}
			free(result);
		}
		else
			printf("a alocaçao de memoria falhou");
	}
	else
		printf("numero invalido de argumentos");
	return (0);
}*/
