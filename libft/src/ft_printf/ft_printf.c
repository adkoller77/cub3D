/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:29:10 by tilogie           #+#    #+#             */
/*   Updated: 2025/02/06 17:40:07 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	printf_len;

	printf_len = 0;
	if (format == 'c')
		printf_len += ft_printchar(va_arg(args, int));
	else if (format == 's')
		printf_len += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		printf_len += ft_ptr_printf(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printf_len += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		printf_len += ft_unsigned_printf(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printf_len += ft_hex_printf(va_arg(args, unsigned int), format);
	else if (format == '%')
		printf_len += ft_printpercent();
	return (printf_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		printf_len;
	va_list	args;

	i = 0;
	printf_len = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			printf_len += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			printf_len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (printf_len);
}
