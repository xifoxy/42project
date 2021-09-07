/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:53 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 14:41:48 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util/util.h"

void	key_rotate(t_win *w)
{
	double	odir_x;
	double	oplane_x;

	if (w->k_d)
	{
		odir_x = w->dx;
		w->dx = w->dx * cos(-0.05) - w->dy * sin(-0.05);
		w->dy = odir_x * sin(-0.05) + w->dy * cos(-0.05);
		oplane_x = w->plane_x;
		w->plane_x = w->plane_x * cos(-0.05) - w->plane_y * sin(-0.05);
		w->plane_y = oplane_x * sin(-0.05) + w->plane_y * cos(-0.05);
	}
	if (w->k_a)
	{
		odir_x = w->dx;
		w->dx = w->dx * cos(0.05) - w->dy * sin(0.05);
		w->dy = odir_x * sin(0.05) + w->dy * cos(0.05);
		oplane_x = w->plane_x;
		w->plane_x = w->plane_x * cos(0.05) - w->plane_y * sin(0.05);
		w->plane_y = oplane_x * sin(0.05) + w->plane_y * cos(0.05);
	}
}

void	key_back_n_forth(t_win *w)
{
	if (w->k_w)
	{
		if (!w->info->map[(int)(w->pos_x + w->dx * 0.05)][(int)(w->pos_y)])
			w->pos_x += w->dx * 0.05;
		if (!w->info->map[(int)(w->pos_x)][(int)(w->pos_y + w->dy * 0.05)])
			w->pos_y += w->dy * 0.05;
	}
	if (w->k_s)
	{
		if (!w->info->map[(int)(w->pos_x - w->dx * 0.05)][(int)(w->pos_y)])
			w->pos_x -= w->dx * 0.05;
		if (!w->info->map[(int)(w->pos_x)][(int)(w->pos_y - w->dy * 0.05)])
			w->pos_y -= w->dy * 0.05;
	}
}

int		key_press(int key, t_win *wins)
{
	if (key == KEY_ESC)
		ft_exit("bye");
	else if (key == KEY_W)
		wins->k_w = 1;
	else if (key == KEY_D)
		wins->k_d = 1;
	else if (key == KEY_S)
		wins->k_s = 1;
	else if (key == KEY_A)
		wins->k_a = 1;
	return (0);
}

int		key_release(int key, t_win *wins)
{
	if (key == KEY_W)
		wins->k_w = 0;
	else if (key == KEY_D)
		wins->k_d = 0;
	else if (key == KEY_S)
		wins->k_s = 0;
	else if (key == KEY_A)
		wins->k_a = 0;
	return (0);
}
