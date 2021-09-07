/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:25:34 by sgang             #+#    #+#             */
/*   Updated: 2021/03/29 21:40:08 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_function_init(void)
{
	*(g_func) = ft_type_char;
	*(g_func + 1) = ft_type_char;
	*(g_func + 2) = ft_type_string;
	*(g_func + 3) = ft_type_number;
	*(g_func + 4) = ft_type_number;
	*(g_func + 5) = ft_type_number;
	*(g_func + 6) = ft_type_number;
	*(g_func + 7) = ft_type_number;
	*(g_func + 8) = ft_type_number;
	*(g_func + 9) = ft_type_pointer;
}

int		ft_print(t_info *lst, va_list args)
{
	int		status;

	if (!lst)
		return (0);
	lst->point = ft_print(lst->next, args);
	if (lst->point == RET_ERROR)
		return (RET_ERROR);
	if (lst->type >= 0)
	{
		ft_get_info(&lst, args);
		status = g_func[lst->type](lst, args);
	}
	else
		status = ft_type_nonvariadic(lst);
	lst->point += status;
	if (status < 0)
		lst->point = RET_ERROR;
	return (lst->point);
}

int		ft_printf(const char *fmt, ...)
{
	int		ret;
	t_info	*lst;
	va_list	args;

	lst = NULL;
	if (ft_parser((char *)fmt, &lst) == RET_ERROR)
		return (ft_free(lst, RET_ERROR));
	ft_function_init();
	va_start(args, fmt);
	ret = ft_print(lst, args);
	va_end(args);
	return (ft_free(lst, ret));
}
