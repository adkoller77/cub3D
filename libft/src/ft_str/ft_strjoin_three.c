/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:11:44 by tilogie           #+#    #+#             */
/*   Updated: 2026/01/12 16:12:10 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_three(char *s1, size_t n, char *s2, char *s3)
{
	char	*name;
	char	*temp;
	char	*result;

	name = ft_substr(s1, 0, n);
	if (!name)
		return (NULL);
	temp = ft_strjoin(name, s2);
	free(name);
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, s3);
	free(temp);
	return (result);
}
