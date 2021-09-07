/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_memory_util.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:24:58 by sgang             #+#    #+#             */
/*   Updated: 2021/03/29 21:36:48 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_memset(char *s, int sz, int ch)
{
	char *temp;

	temp = (char *)s;
	while (sz--)
		*(temp++) = ch;
}

int		ft_free(t_info *lst, int status)
{
	t_info	*iter;
	t_info	*tmp;

	iter = lst;
	while (iter)
	{
		if (iter->format)
			free(iter->format);
		iter->format = 0;
		tmp = iter;
		iter = iter->next;
		free(tmp);
		tmp = 0;
	}
	return (status);
}

void	ft_memcpy(void *dest, const void *src, int count)
{
	const char	*nsrc = "(null)";
	char		*cpy;

	cpy = (char *)dest;
	if (src)
		while (count--)
			*(cpy++) = *(char *)(src++);
	else
		while (count--)
			*(cpy++) = *(char *)(nsrc++);
}

int		ft_calloc(int number, int size, void **ret, char ch)
{
	char	*temp;
	int		idx;

	idx = 0;
	*ret = (char *)malloc(size * number);
	if (!*ret)
		return (RET_ERROR);
	temp = *ret;
	while (idx++ < number * size)
		*(temp++) = ch;
	return (RET_SUCCESS);
}

int		ft_lstnew(char *fmt, int size, t_info **lst, int flag)
{
	t_info	*new_node;

	if (ft_calloc(sizeof(t_info), 1, (void *)&new_node, 0) == RET_ERROR)
		return (RET_ERROR);
	if (ft_calloc(size + 1, 1, (void *)&new_node->format, 0) == RET_ERROR)
		return (RET_ERROR);
	ft_memcpy(new_node->format, fmt, size);
	new_node->type = ft_base(*(fmt + size - 1));
	new_node->check = FALSE;
	if (!flag)
		new_node->type = -1;
	new_node->len = size;
	new_node->base = 10;
	if (new_node->type > 5)
		new_node->base = 16;
	if (!*lst)
		*lst = new_node;
	else
	{
		new_node->next = *lst;
		*lst = new_node;
	}
	return (RET_SUCCESS);
}
