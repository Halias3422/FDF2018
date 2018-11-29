/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 11:21:10 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 16:00:04 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void				display_text(t_map map, int *color)
{
	color = orange_white_black(color, "white");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20, 0x00FFFFF, "MOVE :          ARROWS");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20 + 35, 0x00FFFFF, "ZOOM :          + -");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20 + 70, 0x00FFFFF, "HEIGHT :        PAGE UP / DOWN");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20 + 105, 0x00FFFFF, "RESET :         R");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20 + 140, 0x00FFFFF, "QUIT :          ESC");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20 + 175, 0x00FFFFF, "BG COLOR :      C");
	mlx_string_put(map.mlx_ptr, map.win_ptr, SCREEN_X / 100 * 5, SCREEN_Y /
		100 * 20 + 210, 0x00FFFFF, "FDF COLOR :     X");
}

char				*fill_img(char *str, int x, int y, int *colors)
{
	int				i;

	i = x * 4 + 1920 * y * 4;
	if (x < SCREEN_X - 2 && x > 2 && y < SCREEN_Y - 2 && y > 2 && i <
		SCREEN_Y * SCREEN_X * 4 - 4)
	{
		str[i] = (char)colors[0];
		str[i + 1] = (char)colors[1];
		str[i + 2] = (char)colors[2];
		str[i + 3] = (char)0;
	}
	return (str);
}

static void			top_rectangle(char *img_str, int *color, int s_l, int i)
{
	int			colors;

	while (i <= s_l * 100 - 4)
	{
		colors = 0;
		while (colors < 3)
			img_str[i++] = color[colors++];
		i++;
	}
}

void				fill_image(char *img_str, int *color, int s_l)
{
	int				i;

	i = 0;
	if (!(color = (int*)malloc(sizeof(int) * 3)))
		exit(-1);
	color = orange_white_black(color, "light_blue");
	top_rectangle(img_str, color, s_l, i);
	fox_head(img_str, color);
	free(color);
}
