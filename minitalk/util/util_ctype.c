/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ctype.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:47 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:41:42 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char ch)
{
	return ((ch >= 9 && ch <= 13) || ch == ' ');
}

int	ft_isalpha(char ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int	ft_isdigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int	ft_sign(char ch)
{
	if (ch == '+')
		return (1);
	if (ch == '-')
		return (-1);
	return (0);
}
