/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 15:42:17 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 10:45:23 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

# define SCREEN_X 1920
# define SCREEN_Y 1080

typedef struct			s_img
{
	char				*pt_img;
	int					bp;
	int					s_l;
	int					endian;
	int					*color;
}						t_img;

typedef struct			s_fox
{
	int					i;
	int					or_i;
	int					or_end_line;
	int					end_line;
	int					diff;
	int					colors;
	int					turn;
}						t_fox;

typedef struct			s_map
{
	char				*img_str;
	char				***map_cont;
	int					x;
	int					y;
	int					screen_x;
	int					screen_y;
	int					x_ratio;
	int					y_ratio;
	double				height;
	double				ratio_mult;
	int					pos_x;
	int					pos_y;
	int					dirx;
	int					diry;
	int					sx;
	int					sy;
	int					err;
	int					e2;
	int					bigger_x;
	int					up;
	int					right;
	void				*mlx_ptr;
	void				*win_ptr;
	char				*pt_img;
	int					color;
	int					fdf_color;
}						t_map;

typedef struct			s_bresen
{
	int					x;
	int					y;
	int					x2;
	int					y2;
}						t_bresen;

void					fill_image(char *img_str, int *color, int s_l);
void					fox_head(char *img_str, int *color);
char					*fill_img(char *str, int x, int y, int *colors);
int						*orange_white_black(int *color, char *usage);
char					*reset_screen(char *str, int usage, int check);
int						*rainbow_colors_1(int *color, int usage);
void					display_text(t_map map, int *color);

void					getting_map_on_screen(t_map *map);
int						**char_to_int(char **map_cont);
char					***finalizing_map(char **map_cont);
int						key_press(int keycode, t_map *map);
void					ft_init_map(t_map *map);
int						determ_ratio(char ***map_cont, char *usage, t_map map,
						int *bigger_x);
void					ft_error(void);

#endif
