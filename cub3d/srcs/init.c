/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:50 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 16:52:19 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util/util.h"
#include "mlx/mlx.h"

void	load_textures(t_win *w, t_img *i, char **p)
{
	int		j;
	int		x;
	int		y;

	w->texture = (int **)ft_calloc(5, sizeof(int *), 0);
	j = -1;
	while (++j < 5)
	{
		i->img = mlx_xpm_file_to_image(w->mlx, *(p + j), &i->width, &i->height);
		i->data = (int *)mlx_get_data_addr(i->img, \
			&i->bpp, &i->size, &i->endian);
		w->texture[j] = (int *)ft_calloc(i->width * i->height, sizeof(int), 0);
		w->t_size[j].x = i->width;
		w->t_size[j].y = i->height;
		y = -1;
		while (++y < i->height)
		{
			x = -1;
			while (++x < i->width)
				w->texture[j][i->width * y + x] = i->data[i->width * y + x];
		}
		mlx_destroy_image(w->mlx, i->img);
	}
}

void	init_pdata(t_win *w, const char *direction)
{
	const double	dirx[4] = {-1, 1, 0, 0};
	const double	diry[4] = {0, 0, -1, 1};
	const double	planex[4] = {0, 0, -0.66, 0.66};
	const double	planey[4] = {0.66, -0.66, 0, 0};
	int				idx;

	idx = -1;
	while (++idx < 3)
		w->f_color = w->f_color * 256 + w->info->rgb[0][idx];
	idx = -1;
	while (++idx < 3)
		w->c_color = w->c_color * 256 + w->info->rgb[1][idx];
	idx = -1;
	while (++idx < 4)
		if (w->info->map[w->info->x][w->info->y] == direction[idx])
			break ;
	w->dx = dirx[idx];
	w->dy = diry[idx];
	w->plane_x = planex[idx];
	w->plane_y = planey[idx];
	w->info->map[w->info->x][w->info->y] = 0;
}

void	init_data(t_win *w)
{
	int	x;
	int	y;
	int	idx;

	idx = -1;
	mlx_get_screen_size(w->mlx, &x, &y);
	if (w->info->win[1] < 0)
		w->info->win[1] = y;
	if (w->info->win[0] < 0)
		w->info->win[0] = x;
	w->win_h = ft_min(y, w->info->win[1]);
	w->win_w = ft_min(x, w->info->win[0]);
	w->buf = (int **)ft_calloc(w->win_h, sizeof(int *), 0);
	while (++idx < w->win_h)
		w->buf[idx] = (int *)ft_calloc(w->win_w, sizeof(int), 0);
	w->pos_x = w->info->x * 1.0 + 0.37;
	w->pos_y = w->info->y * 1.0 + 0.37;
	w->zbuf = (double *)ft_calloc(sizeof(double), w->win_w, 0);
	w->win = mlx_new_window(w->mlx, w->win_w, w->win_h, "Cub3D");
	w->img.img = mlx_new_image(w->mlx, w->win_w, w->win_h);
	w->img.data = (int *)mlx_get_data_addr(w->img.img, &w->img.bpp, \
		&w->img.size, &w->img.endian);
}

void	init_textures(t_win *wins, int cnt)
{
	int	x;
	int	y;

	x = -1;
	while (++x < wins->info->hei)
	{
		y = -1;
		while (++y < wins->info->wid)
			if (wins->info->map[x][y] == 2)
				wins->s_cnt++;
	}
	wins->t_pos = (t_tex *)ft_calloc(wins->s_cnt, sizeof(t_tex), 0);
	x = -1;
	while (++x < wins->info->hei)
	{
		y = -1;
		while (++y < wins->info->wid)
			if (wins->info->map[x][y] == 2)
			{
				wins->t_pos[cnt].x = x;
				wins->t_pos[cnt++].y = y;
				wins->info->map[x][y] = 0;
			}
	}
}

void	init_file(char **ag, t_info *info)
{
	const int	fd = open(ag[1], O_RDONLY);

	if (check_name_compare(ag[1], ".cub") == RET_ERROR)
		ft_exit("ERROR check fileName");
	if (fd < 0)
		ft_exit("ERROR the file cannot be found");
	if (parser(info, fd) != MAP_VALID)
		ft_exit("ERROR check for file content");
	close(fd);
	if (check_path(info) == RET_ERROR)
		ft_exit("ERROR invalid info");
	if (parser_rgb(info, 4, 0, 0) == RET_ERROR)
		ft_exit("ERROR check rgb");
	if (parser_winsize(info) == RET_ERROR)
		ft_exit("ERROR check Windows Size");
	if (check_map_source(info, -1, 0) == RET_ERROR)
		ft_exit("ERROR check map source");
	check_map_valid(info);
}
