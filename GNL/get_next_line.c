/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 03:59:10 by sgang             #+#    #+#             */
/*   Updated: 2020/11/23 23:49:33 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		*buf[OPEN_MAX];
	int				sz;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX <= fd || !line)
		return (RET_ERROR);
	if (!*(buf + fd) && !(*(buf + fd) = ft_calloc(BUFFER_SIZE + 1, 1)))
		return (RET_ERROR);
	*line = 0;
	if (ft_strappend(line, *(buf + fd)))
		return (RET_SUCCESS);
	while ((sz = read(fd, *(buf + fd), BUFFER_SIZE)) > 0)
	{
		*(*(buf + fd) + sz) = 0;
		if (ft_strappend(line, *(buf + fd)))
			return (RET_SUCCESS);
	}
	if (sz < 0)
		ft_free(line);
	ft_free(buf + fd);
	return (sz < 0 ? RET_ERROR : RET_EOF);
}
