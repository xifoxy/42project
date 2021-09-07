/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:43:43 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:43:55 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_isspace(char ch)
{
	return ((ch >= 9 && ch <= 13) || ch == 32);
}