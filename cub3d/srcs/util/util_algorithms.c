/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:43:19 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:43:21 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(void *a, void *b, int len)
{
	char	*p;
	char	*q;
	char	temp;
	int		idx;

	p = a;
	q = b;
	idx = -1;
	while (++idx < len)
	{
		temp = p[idx];
		p[idx] = q[idx];
		q[idx] = temp;
	}
}

int		ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int		ft_min(int a, int b)
{
	return (a > b ? b : a);
}

int		ft_safe(int x, int y, int hei, int wid)
{
	return (ft_min(x, y) >= 0 && x < hei && y < wid);
}
