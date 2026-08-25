/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:45:24 by tilogie           #+#    #+#             */
/*   Updated: 2025/02/04 16:54:01 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptr_len(uintptr_t num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_ptr_printf(unsigned long long ptr)
{
	int	printf_len;

	printf_len = 0;
	if (ptr == 0)
		printf_len += write(1, "(nil)", 5);
	else
	{
		printf_len += write(1, "0x", 2);
		ft_put_ptr(ptr);
		printf_len += ft_ptr_len(ptr);
	}
	return (printf_len);
}
