/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   finalizing_map.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 11:13:21 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 10:46:56 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static int		line_len(char **map_cont, int y)
{
	int			x;
	int			nb;

	nb = 0;
	x = 0;
	while (map_cont[y][x])
	{
		if (x == 0 && map_cont[y][x] != 32 && map_cont[y][x] != '\n')
			nb++;
		else if (map_cont[y][x] != 32 && map_cont[y][x] != '\n' &&
			map_cont[y][x - 1] == 32)
			nb++;
		x++;
	}
	return (nb);
}

static void		verif_tab_line(char ***final_tab)
{
	int			y;
	int			x;
	int			len;

	y = 0;
	len = 0;
	while (final_tab[0][len])
		len++;
	while (final_tab[y])
	{
		x = 0;
		while (final_tab[y][x])
			x++;
		if (x != len)
			ft_error();
		y++;
	}
}

char			***finalizing_map(char **map_cont)
{
	char		***final_tab;
	int			y;
	int			x_len;

	y = 0;
	while (map_cont[y])
		y++;
	if (!(final_tab = (char***)malloc(sizeof(char**) * (y + 1))))
		return (NULL);
	y = 0;
	while (map_cont[y])
	{
		x_len = line_len(map_cont, y);
		final_tab[y] = ft_strsplit(map_cont[y], ' ');
		y++;
	}
	final_tab[y] = NULL;
	y = 0;
	while (map_cont[y])
		free(map_cont[y++]);
	free(map_cont);
	verif_tab_line(final_tab);
	return (final_tab);
}
