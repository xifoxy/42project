/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgang <sgang@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:02:47 by sgang             #+#    #+#             */
/*   Updated: 2021/05/25 14:38:59 by sgang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <fcntl.h>
# include <math.h>
# define KEY_RIGHT				124
# define KEY_LEFT				123
# define KEY_ESC				53
# define KEY_W					13
# define KEY_D					2
# define KEY_S					1
# define KEY_A					0
# define DIV					2
# define VMOVE					128.0
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_DESTROY		17

# define INFO_VALID				255
# define MAP_VALID				511

# define TEXTURE_KIND			5

# define RET_ERROR				-1
# define RET_SUCCESS			1
# define RET_EOF				0

# define HEADER_SIZE			14
# define INFO_SIZE				40

typedef struct					s_bmp
{
	int							size;
	char						*img;
	unsigned char				header[14];
	unsigned char				info[40];
	unsigned char				pad[3];
	int							color;
	int							fd;
}								t_bmp;

typedef struct					s_img
{
	void						*img;
	int							*data;
	int							size;
	int							bpp;
	int							endian;
	int							width;
	int							height;
}								t_img;

typedef struct					s_tex
{
	double						y;
	double						x;
	double						dist;
}								t_tex;

typedef struct					s_info
{
	char						*info[8];
	char						**map;
	int							**visit;
	int							rgb[2][4];
	int							win[3];
	int							x;
	int							y;
	int							wid;
	int							hei;
}								t_info;

typedef struct					s_wall
{
	double						ddist_x;
	double						ddist_y;
	double						wallx;
	double						s_distx;
	double						s_disty;
	double						w_dist;
	double						step;
	double						t_pos;
	int							mp_x;
	int							mp_y;
	int							step_x;
	int							step_y;
	int							l_height;
	int							d_start;
	int							d_end;
	int							t_idx;
	int							side;
}								t_wall;

typedef struct					s_sprite
{
	double						spt_x;
	double						spt_y;
	double						invdet;
	double						trans_x;
	double						trans_y;
	int							screen_x;
	int							draws_y;
	int							drawe_y;
	int							draws_x;
	int							drawe_x;
	int							spt_w;
	int							spt_h;
	int							vmove;
}								t_sprite;

typedef struct					s_win
{
	t_sprite					sprite;
	t_tex						t_size[7];
	t_tex						*t_pos;
	t_info						*info;
	t_img						img;
	t_wall						wall;
	void						*mlx;
	void						*win;
	int							k_w;
	int							k_d;
	int							k_s;
	int							k_a;
	int							s_cnt;
	int							**texture;
	int							**buf;
	int							f_color;
	int							c_color;
	int							win_h;
	int							win_w;
	int							tex_x;
	int							tex_y;
	double						*zbuf;
	double						dx;
	double						dy;
	double						pos_x;
	double						pos_y;
	double						plane_x;
	double						plane_y;
	double						rdir_x;
	double						rdir_y;
}								t_win;

void							floor_cast(t_win *wins, int y);
void							get_sprite_dist(t_win *w);
void							sprite_get_value(t_win *wins, t_sprite *s);
void							sprite_init(t_win *w, t_sprite *s, int idx);
void							wall_get_value(t_win *wins, t_wall *w, int y);
void							wall_dda(t_win *wins, t_wall *wall, int y);
void							wall_init(t_win *wins, t_wall *wall, int x);
void							draw(t_win *wins);
void							casting(t_win *wins);
int								check_name_compare(char *f, const char *e);
int								check_path(t_info *info);
void							check_dfs(t_info *t, int x, int y, int **visit);
void							check_map_valid(t_info *info);
int								check_map_source(t_info *info, int x, int y);
void							load_textures(t_win *w, t_img *i, char **p);
void							init_pdata(t_win *w, const char *direction);
void							init_data(t_win *w);
void							init_textures(t_win *wins, int cnt);
void							init_file(char **ag, t_info *info);
void							key_rotate(t_win *wins);
void							key_back_n_forth(t_win *wins);
int								key_press(int key, t_win *wins);
int								key_release(int key, t_win *wins);
int								parser_info(const char *buf, t_info *t);
int								parser_winsize(t_info *info);
int								parser_rgb(t_info *i, int d, int c, int cc);
void							parser_map(char *line, t_info *info);
int								parser(t_info *info, const int fd);
void							save_bmp(t_win *wins);

#endif
