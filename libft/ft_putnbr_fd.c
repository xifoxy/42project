/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 02:22:04 by sgang             #+#    #+#             */
/*   Updated: 2020/10/14 02:26:58 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_recursive(int n, int fd)
{
	if (!n)
		return ;
	ft_recursive(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_recursive((n < 0 ? -(n / 10) : (n / 10)), fd);
	ft_putchar_fd((n < 0 ? -(n % 10) : (n % 10)) + '0', fd);
}
