/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:10:59 by sgang             #+#    #+#             */
/*   Updated: 2020/10/13 22:31:32 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	int		t;

	len = (n < 0 ? 2 : 1);
	t = n;
	while (t /= 10)
		++len;
	if (!(ret = ft_calloc(len + 1, 1)))
		return (0);
	*ret = n < 0 ? '-' : '0';
	while (n)
	{
		t = (n % 10);
		*(ret + --len) = (t < 0 ? -t : t) + '0';
		n /= 10;
	}
	return (ret);
}