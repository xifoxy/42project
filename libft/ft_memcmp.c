/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 05:04:09 by sgang             #+#    #+#             */
/*   Updated: 2020/10/10 06:28:05 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	while (count)
	{
		--count;
		if (*(unsigned char *)buf1 != *(unsigned char *)buf2)
			return (*(unsigned char *)buf1 - *(unsigned char *)buf2);
		buf1++;
		buf2++;
	}
	return (0);
}
