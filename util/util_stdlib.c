/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stdlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:53 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:42:20 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"
#include <stdlib.h>

void	ft_exit(char *msg)
{
	ft_puts((unsigned char *)msg);
	exit(0);
}

int	ft_atoi(char **num, int sign)
{
	long long	ret;

	ret = 0;
	while (ft_isdigit(**num))
	{
		ret = ret * 10 + **num - '0';
		(*num)++;
	}
	if (sign < 0)
		ret = ret * sign;
	return (ret);
}

void	*ft_calloc(int number, int size, char ch)
{
	void	*ret;
	char	*temp;
	int		idx;

	idx = 0;
	ret = malloc(size * number);
	if (!ret)
		ft_exit("ERROR Memory Alloc failure");
	temp = ret;
	while (idx++ < number * size)
		*(temp++) = ch;
	return (ret);
}
