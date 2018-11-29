/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/19 18:50:23 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/28 15:25:37 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static void		fox_eye(char *img_str, int *color, int x, int y)
{
	int			end_line;
	int			or_x;

	color = orange_white_black(color, "black");
	or_x = x;
	end_line = x + 10;
	while (y < 160)
	{
		while (x <= end_line)
			fill_img(img_str, x++, y, color);
		x = or_x;
		y++;
	}
	y = y - 20;
	or_x = or_x + 5;
	x = or_x;
	color = orange_white_black(color, "white");
	while (y < 160)
	{
		while (x <= end_line)
			fill_img(img_str, x++, y, color);
		x = or_x;
		y++;
	}
}

static void		fox_paw(char *img_str, int *color, int x, int end_line)
{
	int			y;
	int			new_x;

	new_x = x;
	y = 80;
	color = orange_white_black(color, "orange");
	while (y < 190)
	{
		while (new_x <= end_line)
			fill_img(img_str, new_x++, y, color);
		y++;
		new_x = x;
	}
	color = orange_white_black(color, "white");
	while (y < 220)
	{
		while (new_x <= end_line)
			fill_img(img_str, new_x++, y, color);
		y++;
		new_x = x;
	}
}

static void		fox_ear(char *img_str, int *color, int x, int end_line)
{
	int			diff;
	int			y;
	int			or_x;

	y = 75;
	diff = 0;
	or_x = x;
	while (end_line > x)
	{
		while (x <= end_line)
			fill_img(img_str, x++, y, color);
		y--;
		end_line--;
		diff++;
		x = or_x + diff;
	}
}

static void		fow_claw(char *img_str, int *color, int x, int end_line)
{
	int			y;
	int			or_x;
	int			diff;
	int			i;

	i = 0;
	diff = 0;
	while (i++ < 3)
	{
		y = 200;
		color = orange_white_black(color, "black");
		or_x = x + diff;
		x = or_x;
		end_line = end_line + diff;
		while (y < 220)
		{
			while (x <= end_line)
				fill_img(img_str, x++, y, color);
			x = or_x;
			y++;
		}
		diff = 20;
	}
}

void			fox_head(char *img_str, int *color)
{
	int			diff;
	int			end_line;
	int			y;
	int			x;

	color = orange_white_black(color, "orange");
	diff = 0;
	end_line = 1160;
	x = 760;
	y = 75;
	while (end_line-- > x && y++ >= 0 && diff++ >= 0)
	{
		while (x <= end_line)
			img_str = fill_img(img_str, x++, y, color);
		x = 760 + diff;
	}
	fox_ear(img_str, color, 760, 910);
	fox_ear(img_str, color, 1010, 1160);
	fox_eye(img_str, color, 910, 105);
	fox_eye(img_str, color, 1000, 105);
	fox_paw(img_str, color, 675, 750);
	fox_paw(img_str, color, 1170, 1245);
	fow_claw(img_str, color, 690, 695);
	fow_claw(img_str, color, 1185, 1190);
}
