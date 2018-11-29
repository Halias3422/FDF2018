/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   key_management.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/27 11:42:03 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 13:10:17 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_map				*move_map(int keycode, t_map *map)
{
	if (keycode == 126)
		map->up++;
	if (keycode == 125)
		map->up--;
	if (keycode == 123)
		map->right--;
	if (keycode == 124)
		map->right++;
	if (keycode == 15)
		ft_init_map(map);
	return (map);
}

int					verif_key(int keycode)
{
	int				res;

	res = 0;
	if ((keycode <= 126 && keycode >= 123) || keycode == 15 || keycode == 53 ||
		keycode == 7 || keycode == 69 || keycode == 69 || keycode == 78 ||
		keycode == 8 || keycode == 116 || keycode == 121)
		res++;
	return (res);
}

int					key_press2(int keycode, t_map *map)
{
	if (keycode == 78 && map->x_ratio > 3)
	{
		map->x_ratio = map->x_ratio < 6 ? 3 : map->x_ratio - 3;
		map->y_ratio = map->y_ratio < 4 ? 2 : map->y_ratio - 2;
	}
	if (keycode == 116)
		map->height += 0.5;
	if (keycode == 121)
		map->height -= 0.5;
	if (keycode == 9)
	{
		if (map->shade == 0)
			map->shade++;
		else
			map->shade--;
		getting_map_on_screen(map);
	}
	if (verif_key(keycode) == 1)
		getting_map_on_screen(map);
	return (0);
}

int					key_press(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(-1);
	if ((keycode >= 123 && keycode <= 126) || keycode == 15)
		map = move_map(keycode, map);
	if (keycode == 8)
	{
		reset_screen(map->img_str, map->color++, 0);
		if (map->color >= 9)
			map->color = 0;
	}
	if (keycode == 7)
	{
		map->shade = 0;
		map->fdf_color++;
		if (map->fdf_color >= 9)
			map->fdf_color = 0;
	}
	if (keycode == 69)
	{
		map->x_ratio += 3;
		map->y_ratio += 2;
	}
	return (key_press2(keycode, map));
}
