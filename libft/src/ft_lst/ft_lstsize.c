/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:01:35 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:40:47 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp_lst;

	i = 0;
	tmp_lst = lst;
	while (tmp_lst)
	{
		tmp_lst = tmp_lst->next;
		i++;
	}
	return (i);
}
