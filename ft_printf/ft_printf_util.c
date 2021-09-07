/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:25:29 by sgang             #+#    #+#             */
/*   Updated: 2021/03/28 18:33:42 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(char *str)
{
	int idx;

	idx = 0;
	while (*str++)
		idx++;
	return (idx);
}

int		ft_base(char ch)
{
	int idx;

	idx = -1;
	while (BASE[++idx])
		if (BASE[idx] == ch)
			return (idx);
	return (RET_ERROR);
}

int		ft_putstr(char **str, int len)
{
	write(1, *str, len);
	if (*str)
		free(*str);
	str = 0;
	return (len);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
