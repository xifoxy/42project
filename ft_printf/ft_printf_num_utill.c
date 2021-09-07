/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num_utill.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:24:48 by sgang             #+#    #+#             */
/*   Updated: 2021/03/29 21:37:17 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

char	ft_pad(t_info *info, void *num, int len)
{
	unsigned long long	unsign;
	long long			sign;

	if (info->check)
		sign = *(long long *)num;
	else
		unsign = *(unsigned long long *)num;
	if ((info->flag & ZEROPAD) && !(info->flag & LEFT))
	{
		if (info->check && sign < 0)
			len++;
		if (info->precision < len && info->precision < 0)
			return ('0');
	}
	return (' ');
}

int		ft_nlen(void *p, t_info *info)
{
	long long			sign;
	unsigned long long	unsign;
	int					len;

	len = 1;
	if (info->check)
	{
		sign = *(long long *)p;
		if (sign < 0)
			info->flag |= PLUS;
		while ((sign > (info->base - 1) || sign < (-info->base + 1)) && len++)
			sign /= info->base;
	}
	else
	{
		unsign = *(unsigned long long *)p;
		while (unsign > (unsigned long long)(info->base - 1) && len++)
			unsign /= info->base;
	}
	if (info->type == 6)
		len += 2;
	return (len);
}

void	ft_numcpy_unsigned(char *dest, int sz, void *num, t_info *info)
{
	unsigned long long	unsign;
	int					type;

	type = 0;
	if (info->type == 8)
		type = 16;
	unsign = *(unsigned long long int *)num;
	while (sz--)
	{
		*(dest--) = DIGIT[(unsign % info->base) + type];
		unsign /= info->base;
	}
	if (info->type == 6 && ++dest)
		*(++dest) = 'x';
	while (info->flag & PLUS && *(dest - 1) == '0')
		dest--;
	if (info->flag & PLUS)
		*dest = '+';
}

void	ft_numcpy(char *dest, int sz, void *num, t_info *info)
{
	long long	sign;
	int			oper;

	if (!info->check)
	{
		ft_numcpy_unsigned(dest, sz, num, info);
		return ;
	}
	oper = 1;
	sign = *(long long *)num;
	if (sign < 0)
		oper = -1;
	while (sz--)
	{
		*(dest--) = DIGIT[(sign % info->base) * oper];
		sign /= info->base;
	}
	while (info->flag & PLUS && dest != info->start && *(dest - 1) == '0')
		dest--;
	if (info->flag & PLUS && oper == 1)
		*dest = '+';
	if (info->flag & PLUS && oper == -1)
		*dest = '-';
}
