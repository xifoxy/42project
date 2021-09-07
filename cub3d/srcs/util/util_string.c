/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:46:18 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 16:45:04 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strnchr(const char *src, char ch, int sz)
{
	int	idx;

	idx = -1;
	while (++idx < sz)
		if (*(src + idx) == ch)
			return (idx);
	return (-1);
}

int	ft_strlen(const char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (idx);
	while (*(str + idx))
		++idx;
	return (idx);
}

int	ft_strncmp(const char *s1, const char *s2, int size)
{
	if (!s1 || !s2)
		return (-1);
	while (size--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}
