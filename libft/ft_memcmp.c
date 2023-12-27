/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:51:29 by luguimar          #+#    #+#             */
/*   Updated: 2023/04/27 11:27:44 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t				i;
	const unsigned char	*b1_;
	const unsigned char	*b2_;

	i = 0;
	b1_ = b1;
	b2_ = b2;
	if (len == 0)
		return (0);
	while (b1_[i] == b2_[i] && i < len - 1)
		i++;
	return (b1_[i] - b2_[i]);
}
