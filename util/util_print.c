/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:51 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:40:52 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	ft_putnum(int num)
{
	if (num > 9)
		ft_putnum(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putchar(unsigned char ch)
{
	write(1, &ch, 1);
}

void	ft_puts(unsigned char *msg)
{
	write(1, msg, ft_strlen((char *)msg));
}
