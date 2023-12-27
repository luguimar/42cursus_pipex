/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:44:13 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/07 18:44:27 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long int	l;
	int			char_counter;

	char_counter = 0;
	l = (long int)n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		char_counter++;
		l = -l;
	}
	if (l > 9)
		char_counter += ft_putnbr_fd(l / 10, fd);
	ft_putchar_fd(l % 10 + '0', fd);
	return (char_counter);
}
