/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelhasni <eelhasni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:45:15 by eelhasni          #+#    #+#             */
/*   Updated: 2022/07/05 17:29:04 by eelhasni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!lst)
		return ;
	tmp1 = *lst;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		ft_lstdelone(tmp1, del);
		tmp1 = tmp2;
	}
	*lst = NULL;
}
