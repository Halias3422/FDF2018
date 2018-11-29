/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 16:04:12 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 13:01:54 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			*orange_white_black(int *color, char *usage)
{
	if (ft_strcmp(usage, "white") == 0)
	{
		color[0] = 255;
		color[1] = 255;
		color[2] = 255;
	}
	else if (ft_strcmp(usage, "orange") == 0)
	{
		color[0] = 0;
		color[1] = 88;
		color[2] = 251;
	}
	else if (ft_strcmp(usage, "black") == 0)
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}
	else if (ft_strcmp(usage, "light_blue") == 0)
	{
		color[0] = 249;
		color[1] = 248;
		color[2] = 215;
	}
	return (color);
}

static int	*rainbow_colors_3(int *color, int usage)
{
	if (usage == 6)
	{
		color[0] = 0;
		color[1] = 182;
		color[2] = 255;
	}
	else if (usage == 7)
	{
		color[0] = 90;
		color[1] = 90;
		color[2] = 210;
	}
	else if (usage == 8)
	{
		color[0] = 220;
		color[1] = 220;
		color[2] = 236;
	}
	return (color);
}

static int	*rainbow_colors_2(int *color, int usage)
{
	if (usage == 3)
	{
		color[0] = 182;
		color[1] = 180;
		color[2] = 94;
	}
	else if (usage == 4)
	{
		color[0] = 108;
		color[1] = 199;
		color[2] = 94;
	}
	else if (usage == 5)
	{
		color[0] = 90;
		color[1] = 208;
		color[2] = 210;
	}
	else if (usage >= 6)
		rainbow_colors_3(color, usage);
	return (color);
}

int			*rainbow_colors_1(int *color, int usage)
{
	if (usage == 0)
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
	}
	else if (usage == 1)
	{
		color[0] = 182;
		color[1] = 94;
		color[2] = 157;
	}
	else if (usage == 2)
	{
		color[0] = 232;
		color[1] = 24;
		color[2] = 36;
	}
	else if (usage >= 3)
		rainbow_colors_2(color, usage);
	return (color);
}

char		*reset_screen(char *str, int usage, int check)
{
	int		*color;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(color = (int*)malloc(sizeof(int) * 3)))
		return (NULL);
	if (check == 0)
	{
		color = rainbow_colors_1(color, usage);
		while (y <= SCREEN_Y)
		{
			while (x <= SCREEN_X)
				fill_img(str, x++, y, color);
			x = 0;
			y++;
		}
	}
	free(color);
	return (str);
}
