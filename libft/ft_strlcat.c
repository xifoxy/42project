/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 04:27:58 by sgang             #+#    #+#             */
/*   Updated: 2020/11/06 00:03:54 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t idx;

	idx = 0;
	while (*dest && idx < size)
	{
		idx++;
		dest++;
	}
	while (*src && idx + 1 < size)
	{
		*dest++ = *src++;
		idx++;
	}
	if (idx < size)
		*dest = 0;
	while (*src)
	{
		idx++;
		src++;
	}
	return (idx);
}
