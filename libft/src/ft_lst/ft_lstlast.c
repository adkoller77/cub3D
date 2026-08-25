/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:12:30 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:40:44 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_lst;

	if (!lst)
		return (NULL);
	tmp_lst = lst;
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	return (tmp_lst);
}
