/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilogie <tilogie@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:05:03 by tilogie           #+#    #+#             */
/*   Updated: 2025/01/10 11:40:43 by tilogie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = lst;
	if (!lst || !f)
		return ;
	while (tmp_lst)
	{
		f(tmp_lst->content);
		tmp_lst = tmp_lst->next;
	}
}
