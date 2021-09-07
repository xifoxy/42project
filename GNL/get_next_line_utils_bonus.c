/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 04:30:28 by sgang             #+#    #+#             */
/*   Updated: 2020/11/24 00:46:30 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t number, size_t size)
{
	char	*ret;
	char	*tmp;
	size_t	idx;

	idx = 0;
	if (!(ret = malloc(size * number)))
		return (0);
	tmp = ret;
	while (idx++ < number * size)
		*(tmp++) = 0;
	return (void*)ret;
}

void	ft_free(char **s1)
{
	if (s1 && *s1)
		free(*s1);
	*s1 = NULL;
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	if (!str || *str == '\n')
		return (0);
	len = 0;
	while (*str != '\n' && *str++)
		len++;
	return (len);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	char	*cpy;

	if (!dest && !src)
		return (0);
	cpy = (char *)dest;
	while (count--)
		*(cpy++) = *(char *)(src++);
	return (dest);
}

int		ft_strappend(char **line, char *buf)
{
	const size_t	l_len = ft_strlen(*line);
	const size_t	b_len = ft_strlen(buf);
	int				ret;
	char			*temp;

	if (!(temp = ft_calloc(l_len + b_len + 1, 1)))
		return (RET_ERROR);
	ft_memcpy(temp, *line, l_len);
	ft_memcpy(temp + l_len, buf, b_len);
	if (*line)
		free(*line);
	*line = temp;
	ret = *(buf + b_len) == '\n' ? RET_SUCCESS : 0;
	ft_memcpy(buf, buf + b_len + 1, BUFFER_SIZE - b_len);
	buf[BUFFER_SIZE - b_len] = 0;
	return (ret);
}
