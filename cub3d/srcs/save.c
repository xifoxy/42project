/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:03:02 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 12:34:22 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util/util.h"

void		set_header(unsigned char *header, int value)
{
	int	idx;

	idx = -1;
	while (++idx < 4)
		*(header + idx) = (unsigned char)(value >> (8 * idx));
}

void		save_bmp_header(t_win *wins, const int fd)
{
	const int		size = 54 + wins->win_h * wins->win_w * 3;
	unsigned char	header[14];
	unsigned char	info[40];

	ft_memset((char *)&header, HEADER_SIZE, 0);
	ft_memset((char *)&info, INFO_SIZE, 0);
	header[0] = 'B';
	header[1] = 'M';
	header[10] = 54;
	info[0] = 40;
	info[12] = 1;
	info[14] = 24;
	set_header(&header[2], size);
	set_header(&info[4], wins->win_w);
	set_header(&info[8], wins->win_h);
	write(fd, header, 14);
	write(fd, info, 40);
}

void		save_bmp_set_color(t_win *wins, const int fd)
{
	const int			padding_size = (4 - (wins->win_w * 3) % 4) % 4;
	const int			padding = 0;
	int					color;
	int					x;
	int					y;

	x = -1;
	while (++x < wins->win_h)
	{
		y = -1;
		while (++y < wins->win_w)
		{
			color = wins->img.data[y + (wins->win_h - x - 1) * wins->win_w];
			write(fd, &color, 3);
		}
		if (padding_size > 0)
			write(fd, &padding, padding_size);
	}
}

void		save_bmp(t_win *wins)
{
	const int fd = open("screen.bmp", O_WRONLY | O_CREAT, 00755);

	if (fd < 0)
		ft_exit("WTF?");
	save_bmp_header(wins, fd);
	save_bmp_set_color(wins, fd);
	close(fd);
}
