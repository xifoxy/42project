/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 01:51:26 by sgang             #+#    #+#             */
/*   Updated: 2020/10/10 06:59:05 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *pos;

	pos = (char *)str;
	while (*pos)
		++pos;
	if (*pos == c)
		return (pos);
	while (*(--pos))
		if (*pos == c || pos == str)
			break ;
	return (*pos == c ? pos : 0);
}
