/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:59 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 14:29:36 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl/gnl.h"
#include "util/util.h"
#include "cub3d.h"

int		parser_winsize(t_info *info)
{
	char	*it;
	int		c;

	c = -1;
	it = info->info[7];
	while (*it && c < 3)
	{
		if (ft_isdigit(*it))
			info->win[++c] = ft_atoi(&it);
		if ((*it && !ft_isspace(*it)) || (c > -1 && !info->win[c]))
			return (RET_ERROR);
		++it;
	}
	if (c != 1)
		return (RET_ERROR);
	return (RET_SUCCESS);
}

int		parser_rgb(t_info *t, int idx, int c, int cc)
{
	char *it;

	idx = 4;
	while (++idx < 7)
	{
		c = -1;
		cc = 0;
		it = t->info[idx];
		while (*it && c < 4)
		{
			if (ft_isdigit(*it) && cc - 1 == c)
				t->rgb[idx % 5][++c] = ft_atoi(&it);
			if (*it == ',')
				++cc;
			if (ft_strnchr(",", *it, 2) == RET_ERROR && !ft_isspace(*it))
				return (RET_ERROR);
			if (c != -1 && (t->rgb[idx % 5][c] > 255 || \
				t->rgb[idx % 5][c] == RET_ERROR))
				return (RET_ERROR);
			++it;
		}
		if (c != 2 || cc != 2)
			return (RET_ERROR);
	}
	return (RET_SUCCESS);
}

void	parser_map(char *line, t_info *info)
{
	char	*st;
	char	*ed;
	int		i;

	if (!line)
		return ;
	i = -1;
	info->map = (char **)ft_calloc(info->hei + 1, sizeof(char *), 0);
	while (++i < info->hei)
		*(info->map + i) = (char *)ft_calloc(info->wid + 1, sizeof(char), 0);
	i = -1;
	ed = line;
	while (*ed)
	{
		st = ed;
		while (*ed && *ed != '\n')
			ed++;
		ft_memcpy(*(info->map + ++i), (const char *)st, ed - st);
		if (*ed)
			++ed;
	}
}

int		parser_info(const char *buf, t_info *t)
{
	const char	*info[8] = {"NO", "SO", "WE", "EA", "S", "F", "C", "R"};
	int			len;
	int			i;
	int			llen;

	while (buf && ft_isspace(*buf))
		buf++;
	len = ft_strlen(buf);
	if (!len)
		return (0);
	i = -1;
	while (++i < 8)
	{
		llen = ft_strlen(info[i]);
		if (!t->info[i] && len >= llen + 1 && \
			ft_isspace(*(buf + llen)) && !ft_strncmp(info[i], buf, llen))
		{
			t->info[i] = ft_calloc(1, len - llen + 2, 0);
			ft_memcpy(t->info[i], buf + llen, len - llen);
			return (1 << i);
		}
	}
	return (1 << 10);
}

int		parser(t_info *info, const int fd)
{
	int		ret;
	int		status;
	char	*line;

	status = 1;
	ret = 0;
	line = 0;
	while (status > 0 && ret < INFO_VALID)
	{
		status = ft_gnl(fd, &line, '\n');
		ret |= parser_info(line, info);
		ft_free(&line);
	}
	status = 1;
	while (status > 0)
	{
		status = ft_gnl(fd, &line, 0);
		info->hei++;
		info->wid = ft_max(info->wid, status - 1);
		ret |= (1 << 8);
	}
	parser_map(line, info);
	ft_free(&line);
	return (ret);
}
