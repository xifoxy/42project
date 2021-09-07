/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:50:16 by sgang             #+#    #+#             */
/*   Updated: 2020/11/05 23:16:00 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char *ret;
	char *pos;

	if (!(ret = ft_calloc(ft_strlen(string) + 1, sizeof(char))))
		return (0);
	pos = ret;
	while (*string)
		*(pos++) = *(string++);
	*pos = 0;
	return (ret);
}
