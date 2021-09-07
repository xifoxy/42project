/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:38:28 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:38:30 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "../util/util.h"

int	ft_append(char **line, char ch, char token)
{
	const int	len = ft_strlen(*line);
	char		*temp;
	int			idx;

	idx = -1;
	temp = ft_calloc(1, len + 2, 0);
	ft_memcpy(temp, *line, len);
	if (token != ch)
		*(temp + len) = ch;
	if (*line)
		free(*line);
	*line = temp;
	return (ch == '\n' ? RET_SUCCESS : 0);
}

int	ft_gnl(int fd, char **line, int token)
{
	char	ch;
	int		status;
	int		len;

	len = 0;
	status = 1;
	while (status > 0)
	{
		status = read(fd, &ch, 1);
		if (status)
			len++;
		if (!*line && ch == ' ' && token == '\n')
			continue ;
		if (status && ft_append(line, ch, token) == RET_SUCCESS)
			return (len);
	}
	if (status < 0)
		ft_exit("ERROR file error");
	return (len);
}
