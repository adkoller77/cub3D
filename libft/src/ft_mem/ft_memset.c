/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:19:07 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:40:54 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp_b;

	temp_b = (unsigned char *) b;
	while (len > 0)
	{
		*(temp_b++) = (unsigned char) c;
		len--;
	}
	return (b);
}
