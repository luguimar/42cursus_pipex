/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:31:54 by luguimar          #+#    #+#             */
/*   Updated: 2023/10/07 15:16:52 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_end_wordquote(char *s, int index, char c)
{
	int	isend;

	isend = 0;
	if (is_end_quote(s, index) || (!quote(s, index) && s[index] != c
			&& (s[index + 1] == c || s[index + 1] == '\0')))
		isend = 1;
	return (isend);
}

int	is_beginning_wordquote(char *s, int index, char c)
{
	int	isbeginning;

	isbeginning = 0;
	if (((index == 0 || s[index - 1] == c) && s[index] != c && !quote(s, index))
		|| is_beginning_quote(s, index))
		isbeginning = 1;
	return (isbeginning);
}

char	**ft_splitquote_nulls(char *s, char c)
{
	char	**result;

	result = ft_splitquote(s, c);
	if (!result)
		return (NULL);
	if (!result[0])
	{
		free(result);
		return (NULL);
	}
	return (result);
}
