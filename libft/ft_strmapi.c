/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 22:33:56 by sgang             #+#    #+#             */
/*   Updated: 2020/10/14 23:42:30 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	idx;

	idx = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(ret = ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (idx < len)
	{
		*(ret + idx) = f(idx, *(s++));
		++idx;
	}
	return (ret);
}
