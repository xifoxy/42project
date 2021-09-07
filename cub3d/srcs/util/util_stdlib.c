/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_stdlib.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:46:14 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:47:57 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	*ft_calloc(int number, int size, char ch)
{
	void	*ret;
	char	*temp;
	int		idx;

	idx = 0;
	ret = malloc(size * number);
	if (!ret)
		ft_exit("ERROR memory alloc failure");
	temp = ret;
	while (idx++ < number * size)
		*(temp++) = ch;
	return (ret);
}

int		ft_atoi(char **str)
{
	int	ret;

	ret = 0;
	while (*str && ft_isdigit(**str))
	{
		ret = ret * 10 + **str - '0';
		(*str)++;
		if (ret < 0)
		{
			while (ft_isdigit(**str))
				(*str)++;
			return (RET_ERROR);
		}
	}
	return (ret);
}

int		ft_exit(const char *err)
{
	const int	len = ft_strlen(err);

	write(0, err, len);
	exit(0);
}
