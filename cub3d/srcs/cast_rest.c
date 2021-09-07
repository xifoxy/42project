/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:36 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:16:40 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util/util.h"

void	floor_cast(t_win *wins, int y)
{
	int	x;

	x = -1;
	while (++x < wins->win_h / 2)
		wins->buf[x][y] = wins->c_color;
	x = wins->win_h / 2 - 1;
	while (++x < wins->win_h)
		wins->buf[x][y] = wins->f_color;
}

void	get_sprite_dist(t_win *w)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = -1;
	while (++i < w->s_cnt)
	{
		x = w->t_pos[i].x;
		y = w->t_pos[i].y;
		w->t_pos[i].dist = ((w->pos_x - x) * (w->pos_x - x) \
			+ (w->pos_y - y) * (w->pos_y - y));
	}
	i = -1;
	while (++i < w->s_cnt)
	{
		j = i;
		while (++j < w->s_cnt)
		{
			if (w->t_pos[i].dist < w->t_pos[j].dist)
				ft_swap((void *)&w->t_pos[i], \
					(void *)&w->t_pos[j], sizeof(t_tex));
		}
	}
}

void	sprite_get_value(t_win *w, t_sprite *s)
{
	int	x;
	int	y;
	int	temp;
	int	color;

	x = s->draws_x - 1;
	while (++x < s->drawe_x)
	{
		w->tex_x = (int)((256 * (x - (-s->spt_w / 2 + s->screen_x)) \
			* w->t_size[4].x / s->spt_w) / 256);
		if (s->trans_y > 0 && x > 0 && x < w->win_w && s->trans_y < w->zbuf[x])
		{
			y = s->draws_y - 1;
			while (++y < s->drawe_y)
			{
				temp = (y - s->vmove) * 256 - w->win_h * 128 + s->spt_h * 128;
				w->tex_y = ((temp * (int)w->t_size[4].y) / s->spt_h) / 256;
				color = w->texture[4][(int)w->t_size[4].x * \
				w->tex_y + w->tex_x];
				if ((color & 0x00FFFFFF) != 0)
					w->buf[y][x] = color;
			}
		}
	}
}

void	sprite_init(t_win *wins, t_sprite *s, int idx)
{
	s->spt_x = wins->t_pos[idx].x + 0.5 - wins->pos_x;
	s->spt_y = wins->t_pos[idx].y + 0.5 - wins->pos_y;
	s->invdet = 1.0 / ((wins->plane_x * wins->dy) - (wins->dx * wins->plane_y));
	s->trans_x = s->invdet * (wins->dy * s->spt_x - wins->dx * s->spt_y);
	s->trans_y = s->invdet * (-wins->plane_y * \
		s->spt_x + wins->plane_x * s->spt_y);
	s->vmove = (int)(VMOVE / s->trans_y);
	s->screen_x = (int)((wins->win_w / 2) * (1 + s->trans_x / s->trans_y));
	s->spt_w = (int)fabs((wins->win_h / s->trans_y) / DIV);
	s->spt_h = (int)fabs((wins->win_h / s->trans_y) / DIV);
	s->draws_y = -s->spt_h / 2 + wins->win_h / 2 + s->vmove;
	s->drawe_y = s->spt_h / 2 + wins->win_h / 2 + s->vmove;
	s->draws_x = -s->spt_w / 2 + s->screen_x;
	s->drawe_x = s->spt_w / 2 + s->screen_x;
	s->draws_y = ft_max(0, s->draws_y);
	s->draws_x = ft_max(0, s->draws_x);
	s->drawe_y = ft_min(wins->win_h - 1, s->drawe_y);
	s->drawe_x = ft_min(wins->win_w - 1, s->drawe_x);
}
