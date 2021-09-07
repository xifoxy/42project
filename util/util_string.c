/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:30:58 by sgang             #+#    #+#             */
/*   Updated: 2021/07/27 19:42:53 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_memcpy(char *dest, char *src, int sz)
{
	char	*temp;

	temp = dest;
	while (sz--)
		*(temp++) = *(char *)(src++);
}

int	ft_strlen(char *str)
{
	int	ret;

	if (!str)
		return (0);
	ret = 0;
	while (*(str + ret))
		++ret;
	return (ret);
}

void	ft_memset(char *dest, int size, char ch)
{
	while (size--)
		*(dest++) = ch;
}

int	ft_strcmp(char *s1, char *s2)
{
	const char	*it1 = s1;
	const char	*it2 = s2;

	while (*it1 && *it2)
	{
		if (*it1 != *it2)
			return (*it1 - *it2);
		++it1;
		++it2;
	}
	return (*it1 - *it2);
}
