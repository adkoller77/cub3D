/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:11:02 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:41:21 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	long	nbr;
	char	*str;

	i = 0;
	nbr = n;
	len = ft_intlen(nbr);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	i = len - 1;
	while (nbr != 0)
	{
		str[i--] = ((nbr % 10) + 48);
		nbr = nbr / 10;
	}
	str[len] = '\0';
	return (str);
}
/*
int	main(int ac, char **av)
{
	(void)ac;
	printf("%s\n", ft_itoa(ft_atoi(av[1])));
	return (0);
}
*/
