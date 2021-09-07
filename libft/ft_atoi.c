/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:36:33 by sgang             #+#    #+#             */
/*   Updated: 2020/10/13 01:59:42 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *string)
{
	int64_t	ret;
	int8_t	flag;

	ret = 0;
	flag = 1;
	while (*string == ' ' || *string == '\t' ||
		*string == '\v' || *string == '\f' ||
		*string == '\n' || *string == '\r')
		string++;
	if (*string == '-' || *string == '+')
	{
		flag = (*string == '-' ? -1 : 1);
		string++;
	}
	while (*string == '0')
		++string;
	while (ft_isdigit(*string))
	{
		ret = ret * 10 + *string - '0';
		string++;
	}
	ret *= flag;
	return (ret);
}
