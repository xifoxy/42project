/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:11:11 by sgang             #+#    #+#             */
/*   Updated: 2020/11/11 05:18:26 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**ret;
	char	*str;
	char	*tmp;
	int		cnt;

	if (!s)
		return (0);
	cnt = ((*s == c || *s == 0) ? 0 : 1);
	str = (char *)s;
	while (*str && *(++str))
		if (*str != c && *(str - 1) == c)
			++cnt;
	if (!(ret = ft_calloc(cnt + 1, sizeof(char *))))
		return (0);
	tmp = str;
	while (cnt--)
	{
		while (str != s && *(str - 1) == c)
			tmp = --str;
		while (str != s && *(str - 1) != c)
			str--;
		*(ret + cnt) = ft_calloc(sizeof(char), tmp - str + 1);
		ft_memcpy(*(ret + cnt), str, tmp - str);
	}
	return (ret);
}
