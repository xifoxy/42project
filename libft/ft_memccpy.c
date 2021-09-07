/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:15:04 by sgang             #+#    #+#             */
/*   Updated: 2020/10/10 05:47:48 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	while (count--)
	{
		*(char *)dest = *(char *)src;
		dest++;
		if (*(char *)src == (char)c)
			return (dest);
		src++;
	}
	return (0);
}
