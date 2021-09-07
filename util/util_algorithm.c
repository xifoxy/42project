/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:45 by sgang             #+#    #+#             */
/*   Updated: 2021/08/08 15:52:08 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

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
		temp = *(p + idx);
		*(p + idx) = *(q + idx);
		*(q + idx) = temp;
	}
}

void	ft_fill(int *first, int *last, int val)
{
	while (first != last)
	{
		*first = val;
		first++;
	}
}
