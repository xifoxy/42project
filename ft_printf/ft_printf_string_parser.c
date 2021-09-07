/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string_parser.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:25:07 by sgang             #+#    #+#             */
/*   Updated: 2021/03/28 18:30:24 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(char **str)
{
	int	ret;

	ret = 0;
	while (ft_isdigit(**str))
	{
		ret = ret * 10 + **str - '0';
		(*str)++;
	}
	return (ret);
}

void	ft_get_format(t_info **lst, char **iter, va_list args)
{
	if (ft_isdigit((char)**iter))
		(*lst)->width = ft_atoi(iter);
	else if (**iter == '*' && (*iter)++)
	{
		(*lst)->width = va_arg(args, int);
		if ((*lst)->width < 0)
		{
			(*lst)->width *= -1;
			(*lst)->flag |= LEFT;
		}
	}
	if (**iter == '.' && (*iter)++)
	{
		(*lst)->precision = 0;
		if (ft_isdigit((char)**(iter)))
			(*lst)->precision = ft_atoi(iter);
		else if (**iter == '*' && (*iter)++)
			(*lst)->precision = va_arg(args, int);
		if ((*lst)->precision < 0)
			(*lst)->precision = -1;
	}
}

void	ft_get_info(t_info **lst, va_list args)
{
	const char	*iter = (*lst)->format;
	int			idx;

	idx = -1;
	while (*iter && ++idx < 8)
	{
		if (FLAG[idx] == *iter)
		{
			++iter;
			if (idx > 4 && (*lst)->flag & (1 << idx))
				(*lst)->flag |= (1 << (idx + 1));
			(*lst)->flag |= (1 << (idx));
			idx = -1;
		}
	}
	(*lst)->width = -1;
	(*lst)->precision = -1;
	ft_get_format(lst, (char **)&iter, args);
}

int		ft_parser(char *fmt, t_info **lst)
{
	char	*it;

	it = fmt;
	while (*it)
	{
		if (*it == '%')
		{
			if (it != fmt && ft_lstnew(fmt, it - fmt, lst, FALSE) == RET_ERROR)
				return (RET_ERROR);
			fmt = ++it;
			while (*(it) && ft_base(*it) < 0)
				++it;
			if (ft_lstnew(fmt, it - fmt + 1, lst, TRUE) == RET_ERROR)
				return (RET_ERROR);
			fmt = ++it;
		}
		else
			it++;
	}
	if (it != fmt && ft_lstnew(fmt, it - fmt, lst, FALSE) == RET_ERROR)
		return (RET_ERROR);
	return (RET_SUCCESS);
}
