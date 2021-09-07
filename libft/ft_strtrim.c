/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 05:13:39 by sgang             #+#    #+#             */
/*   Updated: 2020/10/12 00:41:30 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*st;
	char	*ed;
	char	*ret;

	if (!s1)
		return (0);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		++s1;
	}
	st = (char *)s1;
	ed = (char *)s1;
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			ed = (char *)s1;
		++s1;
	}
	ret = ft_calloc(ed - st + 2, sizeof(char));
	ft_strlcpy(ret, st, ed - st + 2);
	return (ret);
}
