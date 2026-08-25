/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:19:20 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:41:17 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*res;
	char			l;

	i = 0;
	res = NULL;
	l = (char)c;
	while (s[i])
	{
		if (s[i] == l)
			res = (char *)&s[i];
		i++;
	}
	if (s[i] == l)
		res = (char *)&s[i];
	return (res);
}
