/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:40 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:34:43 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

unsigned char	**arr_extend(unsigned char **src, int *sz)
{
	unsigned char	*ret;

	ret = ft_calloc(1, *sz * 2 + 3, 0);
	ft_memcpy((char *)ret, (char *)*src, *sz);
	*sz = *sz * 2 + 1;
	free(*src);
	*src = ret;
	return (src);
}

t_node	*find_pid(t_list *list, pid_t pid)
{
	t_node	*iter;

	iter = list->iter_a;
	while (iter)
	{
		if (iter->pid == pid)
			return (iter);
		iter = iter->next;
	}
	return (0);
}

t_node	*new_node(t_list *list, pid_t pid)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node), 0);
	node->pid = pid;
	if (list->iter_a == NULL)
	{
		list->iter_a = node;
		list->iter_b = node;
	}
	else
	{
		list->iter_b->next = node;
		list->iter_b = list->iter_b->next;
	}
	return (node);
}

void	delete_node(t_node **node, t_list *list)
{
	t_node	*iter;

	if (list->iter_a == *node)
	{
		list->iter_a = list->iter_a->next;
		if (*node == list->iter_b)
			list->iter_b = list->iter_b->next;
	}
	else
	{
		iter = list->iter_a;
		while (iter->next != *node)
			iter = iter->next;
		if (iter->next == list->iter_b)
			list->iter_b = iter;
		iter->next = iter->next->next;
	}
	free((*node)->msg);
	(*node)->msg = 0;
	free(*node);
	*node = 0;
}
