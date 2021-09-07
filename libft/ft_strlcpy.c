/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:39:34 by sgang             #+#    #+#             */
/*   Updated: 2020/10/13 03:01:00 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t len;
	size_t idx;

	if (!dest || !src)
		return (0);
	len = ft_strlen(src);
	idx = len < size - 1 ? len : size - 1;
	if (size)
	{
		ft_memcpy(dest, src, idx);
		*(dest + idx) = 0;
	}
	return (len);
}
