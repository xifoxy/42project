/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:45:54 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:45:55 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_memset(char *dest, int size, char ch)
{
	while (size--)
		*(dest++) = ch;
}

void	ft_memcpy(char *dest, const char *src, int sz)
{
	char	*temp;

	temp = dest;
	while (sz--)
		*(temp++) = *(char *)(src++);
}

void	ft_free(char **temp)
{
	if (*temp)
		free(*temp);
	*temp = 0;
}
