/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_string.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:33:54 by sgang             #+#    #+#             */
/*   Updated: 2021/03/28 18:36:38 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type_string(t_info *info, va_list args)
{
	const char	*s = va_arg(args, char *);
	int			len;
	int			ret;
	char		*buf;

	if (s == NULL)
		len = 6;
	else
		len = (int)ft_strlen((char *)s);
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	ret = ft_max(len, info->width);
	if (ft_calloc(ret + 1, 1, (void *)&buf, ' ') == RET_ERROR)
		return (RET_ERROR);
	if (!(info->flag & LEFT))
		ft_memcpy(buf + ret - len, s, len);
	else
		ft_memcpy(buf, s, len);
	return (ft_putstr(&buf, ret));
}

int	ft_type_char(t_info *info, va_list args)
{
	char	ch;
	char	*buf;
	char	flag;
	int		ret;

	flag = ' ';
	if ((info->flag & ZEROPAD) && !(info->flag & LEFT))
		flag = '0';
	ch = '%';
	if (info->type != 1)
		ch = va_arg(args, int);
	ret = ft_max(info->width, 1);
	if (ft_calloc(1, ret + 1, (void *)&buf, flag) == RET_ERROR)
		return (RET_ERROR);
	if (info->flag & LEFT)
		*buf = ch;
	else
		*(buf + ret - 1) = ch;
	return (ft_putstr(&buf, ret));
}

int	ft_type_nonvariadic(t_info *info)
{
	write(1, info->format, info->len);
	return (info->len);
}
