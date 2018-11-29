/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   creating_map.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 14:48:16 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 15:57:09 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		getting_line(t_bresen *bresen, char *img_str, int *color)
{
	t_map		map;

	map.dirx = ft_abs(bresen->x2 - bresen->x);
	map.diry = ft_abs(bresen->y2 - bresen->y);
	map.sx = bresen->x < bresen->x2 ? 1 : -1;
	map.sy = bresen->y < bresen->y2 ? 1 : -1;
	map.err = (map.dirx > map.diry ? map.dirx : -map.diry) / 2;
	while (1)
	{
		fill_img(img_str, bresen->x, bresen->y, color);
		if (bresen->x == bresen->x2 && bresen->y == bresen->y2)
			break ;
		map.e2 = map.err;
		if (map.e2 > -map.dirx)
		{
			map.err -= map.diry;
			bresen->x += map.sx;
		}
		if (map.e2 < map.diry)
		{
			map.err += map.dirx;
			bresen->y += map.sy;
		}
	}
}

int				determ_ratio(char ***map_cont, char *usage, t_map map,
		int *bigger_x)
{
	int			size;

	ft_strcmp(usage, "usage y") == 0 ? map.x_ratio = 60 : 0;
	map.y = -1;
	if (*bigger_x == 0)
	{
		while (map_cont[++map.y])
		{
			map.x = 0;
			while (map_cont[map.y][map.x])
				map.x++;
			if (map.x > *bigger_x)
				*bigger_x = map.x;
		}
		if (*bigger_x < map.y)
			*bigger_x = map.y;
	}
	size = *bigger_x;
	while (size > 10 && map.x_ratio >= 4 && map.y_ratio >= 3)
	{
		size = size / 2;
		map.x_ratio = map.x_ratio < 3 ? 3 : map.x_ratio / 2;
		map.y_ratio = map.y_ratio < 2 ? 2 : map.y_ratio / 2;
	}
	return ((ft_strcmp(usage, "usage x") == 0) ? map.x_ratio : map.y_ratio);
}

static t_bresen	*init_bresen(t_bresen *bresen, t_map map, char ***map_cont,
		int usage)
{
	if (usage == 0)
	{
		bresen->x = map.pos_x;
		bresen->y = map.pos_y - (ft_atoi(map_cont[map.y][map.x]) * map.height *
			map.y_ratio) / 10;
		bresen->x2 = map.pos_x + map.x_ratio;
		bresen->y2 = map.pos_y + map.y_ratio - (ft_atoi(map_cont[map.y][map.x +
			1]) * map.height * map.y_ratio) / 10;
	}
	if (usage == 1)
	{
		bresen->x = map.pos_x;
		bresen->y = map.pos_y - (ft_atoi(map_cont[map.y][map.x]) * map.height *
			map.y_ratio) / 10;
		bresen->x2 = map.pos_x - map.x_ratio;
		bresen->y2 = map.pos_y + map.y_ratio - (ft_atoi(map_cont[map.y + 1]
			[map.x]) * map.height * map.y_ratio) / 10;
	}
	return (bresen);
}

static void		point_on_screen(char ***map_cont, char *img_str, t_map map,
		int *color)
{
	t_bresen		bresen;

	if (map_cont[map.y][map.x + 1] != '\0')
	{
		map.pos_x = map.screen_x - (map.x_ratio * map.y) +
			(map.x_ratio * map.x + 1);
		map.pos_y = map.screen_y + (map.y_ratio * map.y) +
			(map.y_ratio * map.x + 1);
		getting_line(init_bresen(&bresen, map, map_cont, 0), img_str, color);
	}
	if (map_cont[map.y + 1] != '\0')
	{
		map.pos_x = map.screen_x - (map.x_ratio * map.y + 1) +
			(map.x_ratio * map.x);
		map.pos_y = map.screen_y + (map.y_ratio * map.y + 1) +
			(map.y_ratio * map.x);
		getting_line(init_bresen(&bresen, map, map_cont, 1), img_str, color);
	}
}

void			getting_map_on_screen(t_map *map)
{
	int			*color;

	map->img_str = reset_screen(map->img_str, map->color, 0);
	map->screen_x = SCREEN_X / 100 * (45 + map->right);
	map->screen_y = SCREEN_Y / 100 * (30 - map->up);
	if (!(color = (int*)malloc(sizeof(int) * 3)))
		exit(-1);
	color = rainbow_colors_1(color, map->fdf_color);
	map->y = 0;
	while (map->map_cont[map->y])
	{
		map->x = 0;
		while (map->map_cont[map->y][map->x])
		{
			point_on_screen(map->map_cont, map->img_str, *map, color);
			map->x++;
		}
		map->y++;
	}
	fill_image(map->img_str, color, SCREEN_X * 4);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->pt_img, 0, 0);
	display_text(*map, color);
	free(color);
}
