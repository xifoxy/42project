/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:27 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 14:47:11 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx/mlx.h"

void	draw(t_win *w)
{
	int	x;
	int	y;

	x = -1;
	while (++x < w->win_h)
	{
		y = -1;
		while (++y < w->win_w)
			w->img.data[x * w->win_w + y] = w->buf[x][y];
	}
	mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
}

void	casting(t_win *wins)
{
	int	idx;

	idx = -1;
	while (++idx < wins->win_w)
		floor_cast(wins, idx);
	idx = -1;
	while (++idx < wins->win_w)
	{
		wins->wall.mp_x = (int)wins->pos_x;
		wins->wall.mp_y = (int)wins->pos_y;
		wall_init(wins, &wins->wall, idx);
		wall_dda(wins, &wins->wall, idx);
		wall_get_value(wins, &wins->wall, idx);
	}
	get_sprite_dist(wins);
	idx = -1;
	while (++idx < wins->s_cnt)
	{
		sprite_init(wins, &wins->sprite, idx);
		sprite_get_value(wins, &wins->sprite);
	}
}
