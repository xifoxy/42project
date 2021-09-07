/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 23:51:35 by sgang             #+#    #+#             */
/*   Updated: 2020/10/10 00:06:46 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	if (dest > src)
		while (count--)
			*(unsigned char *)(dest + count) =
			*(unsigned const char *)(src + count);
	else
		ft_memcpy(dest, src, count);
	return (dest);
}
