/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:42:23 by tilogie           #+#    #+#             */
/*   Updated: 2025/02/04 16:54:02 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_num_len(unsigned	int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num = num / 10;
	}
	return (i);
}

char	*ft_uitoa(unsigned int n)
{
	int		len;
	char	*num;

	len = ft_num_len(n);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_unsigned_printf(unsigned int n)
{
	int		printf_len;
	char	*num;

	printf_len = 0;
	if (n == 0)
		printf_len += write(1, "0", 1);
	else
	{
		num = ft_uitoa(n);
		printf_len += ft_printstr(num);
		free(num);
	}
	return (printf_len);
}
