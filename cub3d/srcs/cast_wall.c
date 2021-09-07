/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:39 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 14:46:30 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util/util.h"

void	wall_get_value(t_win *ww, t_wall *w, int y)
{
	int	c;
	int idx;

	w->d_start = ft_max(-w->l_height / 2 + ww->win_h / 2, 1);
	w->d_end = ft_min(w->l_height / 2 + ww->win_h / 2, ww->win_h - 1);
	w->t_idx = (ww->rdir_y > 0 ? 3 : 2);
	if (!w->side)
		w->t_idx = (ww->rdir_x < 0 ? 0 : 1);
	ww->tex_x = (int)(w->wallx * (double)ww->t_size[w->t_idx].y);
	if ((!w->side && ww->rdir_x > 0) || (w->side && ww->rdir_y < 0))
		ww->tex_x = ww->t_size[w->t_idx].y - ww->tex_x - 1;
	w->step = (double)ww->t_size[w->t_idx].x / w->l_height;
	w->t_pos = (w->d_start - ww->win_h / 2 + w->l_height / 2) * w->step;
	while (w->d_start < w->d_end)
	{
		ww->tex_y = (int)w->t_pos & (int)(ww->t_size[w->t_idx].x - 1);
		w->t_pos += w->step;
		idx = (int)ww->t_size[w->t_idx].x * ww->tex_y + ww->tex_x;
		c = ww->texture[w->t_idx][idx];
		if (w->side)
			c = (c >> 1) & 8355711;
		ww->buf[w->d_start++][y] = c;
	}
}

void	wall_dda(t_win *wins, t_wall *w, int x)
{
	while (!wins->info->map[w->mp_x][w->mp_y])
	{
		if (w->s_distx < w->s_disty)
		{
			w->s_distx += w->ddist_x;
			w->mp_x += w->step_x;
			w->side = 0;
		}
		else
		{
			w->s_disty += w->ddist_y;
			w->mp_y += w->step_y;
			w->side = 1;
		}
	}
	w->w_dist = (w->mp_y - wins->pos_y + (1 - w->step_y) / 2) / wins->rdir_y;
	w->wallx = wins->pos_x + w->w_dist * wins->rdir_x;
	if (!w->side)
		w->w_dist = (w->mp_x - wins->pos_x + \
		(1 - w->step_x) / 2) / wins->rdir_x;
	if (!w->side)
		w->wallx = wins->pos_y + w->w_dist * wins->rdir_y;
	w->wallx -= floor(w->wallx);
	w->l_height = (int)(wins->win_h / w->w_dist);
	wins->zbuf[x] = w->w_dist;
}

void	wall_init(t_win *wins, t_wall *wall, int x)
{
	wins->rdir_x = wins->dx + wins->plane_x * (2 * x / (double)wins->win_w - 1);
	wins->rdir_y = wins->dy + wins->plane_y * (2 * x / (double)wins->win_w - 1);
	wall->ddist_x = fabs(1 / wins->rdir_x);
	wall->ddist_y = fabs(1 / wins->rdir_y);
	if (wins->rdir_x < 0)
	{
		wall->step_x = -1;
		wall->s_distx = (wins->pos_x - wall->mp_x) * wall->ddist_x;
	}
	else
	{
		wall->step_x = 1;
		wall->s_distx = (wall->mp_x + 1.0 - wins->pos_x) * wall->ddist_x;
	}
	if (wins->rdir_y < 0)
	{
		wall->step_y = -1;
		wall->s_disty = (wins->pos_y - wall->mp_y) * wall->ddist_y;
	}
	else
	{
		wall->step_y = 1;
		wall->s_disty = (wall->mp_y + 1.0 - wins->pos_y) * wall->ddist_y;
	}
}
