/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 06:51:11 by sgang             #+#    #+#             */
/*   Updated: 2020/10/15 03:03:07 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*iter;
	t_list	*ret;
	t_list	*flag;

	ret = 0;
	iter = lst;
	flag = 0;
	while (iter)
	{
		flag = ft_lstnew(f(iter->content));
		if (flag)
			ft_lstadd_back(&ret, flag);
		iter = iter->next;
	}
	if (!flag)
		ft_lstiter(ret, del);
	return (flag ? ret : 0);
}
