/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:38:37 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:38:39 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util/util.h"

void	check_dfs(t_info *t, int x, int y, int **visit)
{
	static const int	dx[4] = {1, -1, 0, 0};
	static const int	dy[4] = {0, 0, 1, -1};
	int					idx;
	int					nx;
	int					ny;

	if (ft_min(x - 1, y - 1) < 0 || \
			!ft_safe(x + 1, y + 1, t->hei, t->wid) || t->map[x][y] == -1)
		ft_exit("ERROR invalid map");
	idx = -1;
	visit[x][y] = 1;
	while (++idx < 4)
	{
		nx = x + dx[idx];
		ny = y + dy[idx];
		if (t->map[nx][ny] == 1 || visit[nx][ny])
			continue;
		check_dfs(t, nx, ny, visit);
	}
}

void	check_map_valid(t_info *info)
{
	int	idx;
	int	**visit;

	idx = -1;
	visit = ft_calloc(info->hei, sizeof(int **), 0);
	while (++idx < info->hei)
		*(visit + idx) = ft_calloc(info->wid, sizeof(int *), 0);
	check_dfs(info, info->x, info->y, visit);
	idx = -1;
	while (++idx < info->hei)
		free(visit[idx]);
	free(visit);
}

int		check_map_source(t_info *info, int x, int y)
{
	int			ret;

	info->x = RET_ERROR;
	while (++x < info->hei)
	{
		y = -1;
		while (++y < info->wid)
		{
			ret = ft_strnchr("NSEW120", info->map[x][y], 8);
			if (ret == RET_ERROR && ft_isspace(info->map[x][y]))
				continue;
			if (ret < 4 && info->x != -1)
				return (RET_ERROR);
			if (ret < 4)
			{
				info->x = x;
				info->y = y;
			}
			if (ft_isdigit(info->map[x][y]))
				info->map[x][y] -= '0';
			else if (info->map[x][y] == ' ')
				info->map[x][y] = -1;
		}
	}
	return (info->x);
}

int		check_name_compare(char *filename, const char *extension)
{
	const int	fl = ft_strlen(filename);
	const int	el = ft_strlen(extension);
	int			idx;

	idx = -1;
	while (++idx < fl)
	{
		if (*(filename + idx) >= 'A' && *(filename + idx) <= 'Z')
			*(filename + idx) += 32;
	}
	if (fl < el || ft_strncmp(filename + fl - el, extension, el))
		return (RET_ERROR);
	return (RET_SUCCESS);
}

int		check_path(t_info *info)
{
	const char	*extension = ".xpm";
	char		*iter;
	int			idx;
	int			fd;

	idx = -1;
	while (++idx < 5)
	{
		iter = info->info[idx];
		while (ft_isspace(*iter))
			iter++;
		fd = open(iter, O_RDONLY);
		if (check_name_compare(iter, extension) == RET_ERROR || fd < 0)
			return (RET_ERROR);
		ft_memcpy(info->info[idx], iter, ft_strlen(iter) + 1);
		close(fd);
	}
	return (RET_SUCCESS);
}
