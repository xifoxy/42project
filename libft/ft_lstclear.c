/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 06:23:11 by sgang             #+#    #+#             */
/*   Updated: 2020/10/14 06:40:11 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *iter;
	t_list *tmp;

	iter = *lst;
	while (iter)
	{
		tmp = iter;
		iter = iter->next;
		del(tmp);
	}
	*lst = 0;
}
