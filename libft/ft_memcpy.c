/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 20:49:59 by sgang             #+#    #+#             */
/*   Updated: 2020/10/20 23:33:13 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char	*cpy;

	if (!dest && !src)
		return (0);
	cpy = (char *)dest;
	while (count--)
		*(cpy++) = *(char *)(src++);
	return (dest);
}
