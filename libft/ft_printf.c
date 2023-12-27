/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luguimar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 02:35:16 by luguimar          #+#    #+#             */
/*   Updated: 2023/09/21 15:12:02 by luguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	typeconversor1(char ch, va_list args)
{
	char	*str;

	if (ch == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			return (ft_putstr_fd("(null)", 1));
		else
			return (ft_putstr_fd(str, 1));
	}
	else if (ch == 'u')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789", 1));
	else if (ch == 'x')
		return (ft_putnbr_base_fd(va_arg(args, unsigned int),
				"0123456789abcdef", 1));
	else
		return (ft_putnbr_base_fd(va_arg(args, unsigned int),
				"0123456789ABCDEF", 1));
}

int	typeconversor2(char ch, va_list args)
{
	char			*nbr_in_str;
	int				char_counter;
	unsigned long	ptr;

	char_counter = 0;
	if (ch == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (!ptr)
			return (ft_putstr_fd("(nil)", 1));
		else
			return (ft_putstr_fd("0x", 1) + ft_putnbr_base_fd(ptr,
					"0123456789abcdef", 1));
	}
	else
	{
		nbr_in_str = ft_itoa(va_arg(args, int));
		char_counter = ft_putstr_fd(nbr_in_str, 1);
		free(nbr_in_str);
		return (char_counter);
	}
}

int	checktype(int ch, va_list args)
{
	if (ch == 'c')
		return (ft_putchar_fd(va_arg(args, int), 1));
	else if (ch == 's')
		return (typeconversor1(ch, args));
	else if (ch == 'p')
		return (typeconversor2(ch, args));
	else if (ch == 'd' || ch == 'i')
		return (typeconversor2(ch, args));
	else if (ch == 'u')
		return (typeconversor1(ch, args));
	else if (ch == 'x')
		return (typeconversor1(ch, args));
	else if (ch == 'X')
		return (typeconversor1(ch, args));
	else if (ch == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_counter;
	int		i;

	va_start(args, str);
	char_counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			char_counter += checktype(str[i], args);
		}
		else
			char_counter += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (char_counter);
}
/*
int	main(void)
{
	ft_printf("dfigvjfdkgv");
	return (0);
}*/
