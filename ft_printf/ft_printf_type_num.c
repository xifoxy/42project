/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:25:14 by sgang             #+#    #+#             */
/*   Updated: 2021/03/28 18:43:08 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_pointer(t_info *info, va_list args)
{
	if ((info->flag & LL))
		*((long long int *)va_arg(args, long long int *)) = info->point;
	else if ((info->flag & L))
		*((long int *)va_arg(args, long int *)) = info->point;
	else if ((info->flag & HH))
		*((signed char *)va_arg(args, signed char *)) = info->point;
	else if ((info->flag & H))
		*((short int *)va_arg(args, short int *)) = info->point;
	else
		*(va_arg(args, int *)) = info->point;
	return (0);
}

int	ft_type_num(t_info *info, void *num)
{
	const int	len = ft_max(ft_nlen(num, info), info->precision);
	const char	padding = ft_pad(info, num, len);
	int			ret;
	char		*buf;

	ret = ft_max(len, info->width);
	if (ft_num_check(num, info->check) < 0 && ret <= len)
		ret++;
	if (!info->precision && !ft_num_check(num, info->check) && info->width <= 0)
		ret = 0;
	if (ft_calloc(1, ret + 1, (void *)&buf, padding) == RET_ERROR)
		return (RET_ERROR);
	info->start = buf;
	if (!info->precision && !ft_num_check(num, info->check))
		ft_memset(buf, ret, ' ');
	else if (info->flag & LEFT)
	{
		if (info->flag & PLUS)
			ft_numcpy(buf + len, len, num, info);
		else
			ft_numcpy(buf + len - 1, len, num, info);
	}
	else
		ft_numcpy(buf + ret - 1, len, num, info);
	return (ft_putstr(&buf, ret));
}

int	ft_num_excep(t_info *info)
{
	int		ret;
	char	*str;

	ret = ft_max(info->width, 3);
	if (!info->precision && info->width < 3)
		ret--;
	if (ft_calloc(ret + 1, 1, (void *)&str, ' ') == RET_ERROR)
		return (RET_ERROR);
	if (info->flag & LEFT && !info->precision)
		ft_memcpy(str, "0x", 2);
	else if (info->flag & LEFT)
		ft_memcpy(str, "0x0", 3);
	else if (!info->precision)
		ft_memcpy(str + ret - 2, "0x", 2);
	else
		ft_memcpy(str + ret - 3, "0x0", 3);
	return (ft_putstr(&str, ret));
}

int	ft_type_number(t_info *info, va_list args)
{
	long long			sign;
	unsigned long long	unsign;

	if (info->type < 5)
	{
		info->check = TRUE;
		if (info->flag & LL)
			sign = va_arg(args, long long);
		else
			sign = va_arg(args, int);
		return (ft_type_num(info, (void *)&sign));
	}
	else
	{
		if (info->flag & LL || info->type == 6)
			unsign = va_arg(args, unsigned long long);
		else
			unsign = va_arg(args, unsigned);
		if (info->type == 6 && unsign == 0)
			return (ft_num_excep(info));
	}
	return (ft_type_num(info, (void *)&unsign));
}

int	ft_num_check(void *num, int signcheck)
{
	if (signcheck && *(long long *)num)
	{
		if (*(long long *)num < 0)
			return (-1);
		return (TRUE);
	}
	else if (!signcheck && *(unsigned long long *)num)
		return (TRUE);
	return (FALSE);
}
