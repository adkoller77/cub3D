/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:18:06 by tilogie           #+#    #+#             */
/*   Updated: 2025/11/27 14:25:11 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr_fd(char *s, size_t n, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < n)
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
