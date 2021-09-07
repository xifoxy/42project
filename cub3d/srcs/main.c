/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:56 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 14:38:16 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "util/util.h"
#include "mlx/mlx.h"

int		loop(t_win *wins)
{
	casting(wins);
	draw(wins);
	key_back_n_forth(wins);
	key_rotate(wins);
	return (0);
}

void	run(int ac, t_win *w)
{
	if (ac == 3)
	{
		loop(w);
		save_bmp(w);
		exit(0);
	}
	mlx_loop_hook(w->mlx, &loop, w);
	mlx_hook(w->win, X_EVENT_DESTROY, 0, &ft_exit, "bye");
	mlx_hook(w->win, X_EVENT_KEY_PRESS, 0, &key_press, w);
	mlx_hook(w->win, X_EVENT_KEY_RELEASE, 0, &key_release, w);
	mlx_loop(w->mlx);
}

void	init(int ac, char **ag)
{
	t_win	wins;
	t_info	info;

	ft_memset((char *)&wins, sizeof(t_win), 0);
	ft_memset((char *)&info, sizeof(t_info), 0);
	wins.mlx = mlx_init();
	init_file(ag, &info);
	wins.info = &info;
	load_textures(&wins, &wins.img, wins.info->info);
	init_textures(&wins, 0);
	init_data(&wins);
	init_pdata(&wins, "NSWE");
	run(ac, &wins);
}

int		main(int ac, char **ag)
{
	if (ac < 2 || ac > 3)
		ft_exit("ERROR check parameter");
	if (ac == 3 && check_name_compare(ag[2], "--save") == RET_ERROR)
		ft_exit("ERROR check parameter");
	init(ac, ag);
}
