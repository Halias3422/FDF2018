/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:47:59 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 13:41:19 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void			ft_error(void)
{
	ft_putendl("error opening map");
	exit(-1);
}

void			ft_init_map(t_map *map)
{
	map->right = 0;
	map->up = 0;
	map->color = 0;
	map->fdf_color = 8;
	map->x_ratio = 60;
	map->y_ratio = 40;
	map->height = 3;
	map->bigger_x = 0;
	map->shade = 0;
	map->x_ratio = determ_ratio(map->map_cont, "usage x", *map,
			&(map->bigger_x));
	map->y_ratio = determ_ratio(map->map_cont, "usage y", *map,
			&(map->bigger_x));
}

char			***read_and_store_map(int fd)
{
	char		*line;
	char		*content;
	char		*tmp;
	char		**map_cont;

	content = ft_strnew(1);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strjoin(content, line);
		free(content);
		content = tmp;
		free(line);
	}
	free(line);
	map_cont = ft_strsplit(content, '\n');
	free(content);
	return (finalizing_map(map_cont));
}

static void		free_all(t_map *map, t_img *img)
{
	int			y;
	int			x;

	y = 0;
	free(img->pt_img);
	free(img->color);
	free(map->img_str);
	free(map->mlx_ptr);
	free(map->win_ptr);
	free(map->pt_img);
	while (map->map_cont[y])
	{
		x = 0;
		while (map->map_cont[y][x])
			free(map->map_cont[y][x++]);
		free(map->map_cont[y++]);
	}
	free(map->map_cont);
}

int				main(int ac, char **av)
{
	t_img		img;
	t_map		*map;
	int			fd;

	if (ac == 2)
	{
		if (!(map = (t_map*)malloc(sizeof(t_map))))
			exit(0);
		((fd = open(av[1], O_RDWR)) == -1) ? ft_error() : 0;
		map->map_cont = read_and_store_map(fd);
		map->mlx_ptr = mlx_init();
		map->win_ptr = mlx_new_window(map->mlx_ptr, SCREEN_X, SCREEN_Y, "FDF");
		map->pt_img = mlx_new_image(map->mlx_ptr, SCREEN_X, SCREEN_Y);
		map->img_str = mlx_get_data_addr(map->pt_img, &img.bp, &img.s_l,
				&img.endian);
		ft_init_map(map);
		getting_map_on_screen(map);
		mlx_hook(map->win_ptr, 2, 0, key_press, (void*)map);
		mlx_loop(map->mlx_ptr);
		free_all(map, &img);
	}
	else
		ft_putendl("usage : ./fdf target_file");
	return (0);
}
