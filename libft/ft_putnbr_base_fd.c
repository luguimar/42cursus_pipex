/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:15:34 by luguimar          #+#    #+#             */
/*   Updated: 2023/05/31 18:27:06 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base_fd(unsigned long decimal, char *base, int fd)
{
	int				char_counter;
	unsigned long	baselen;

	baselen = ft_strlen(base);
	char_counter = 0;
	if (decimal >= baselen)
	{
		char_counter += ft_putnbr_base_fd(decimal / baselen, base, fd);
		char_counter += ft_putnbr_base_fd(decimal % baselen, base, fd);
	}
	else
	{
		char_counter += ft_putchar_fd(base[decimal], fd);
	}
	return (char_counter);
}
