/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.42belgium.be>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 01:50:05 by tilogie           #+#    #+#             */
/*   Updated: 2026/01/16 02:15:35 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_array(char **array)
{
	char	**dup;
	int		i;

	if (!array)
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	dup = malloc((i + 1) * sizeof(char *));
	if (!dup)
		return (NULL);
	i = 0;
	while (array[i])
	{
		dup[i] = ft_strdup(array[i]);
		if (!dup[i])
		{
			ft_array_free(dup);
			return (NULL);
		}
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
