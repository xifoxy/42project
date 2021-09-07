/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:13:20 by sgang             #+#    #+#             */
/*   Updated: 2020/10/11 01:26:02 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	b_len;
	size_t	l_len;
	int		cnt;

	b_len = ft_strlen(big);
	l_len = ft_strlen(little);
	cnt = (b_len < len ? b_len : len) - l_len + 1;
	if (!l_len)
		return ((char *)big);
	while (cnt-- > 0)
	{
		if (*big == *little && !ft_strncmp(big, little, l_len))
			return ((char *)big);
		++big;
	}
	return (0);
}
