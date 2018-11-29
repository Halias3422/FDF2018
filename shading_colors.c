/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   shading_colors.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 12:48:57 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 13:12:02 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			*shading_colors4(int *color, int altitude)
{
	if (altitude >= -80 && altitude <= -61)
	{
		color[0] = 78;
		color[1] = 51;
		color[2] = 231;
	}
	if (altitude <= -81)
	{
		color[0] = 4;
		color[1] = 4;
		color[2] = 250;
	}
	return (color);
}

int			*shading_colors3(int *color, int altitude)
{
	if (altitude >= -20 && altitude <= -1)
	{
		color[0] = 237;
		color[1] = 44;
		color[2] = 152;
	}
	if (altitude >= -40 && altitude <= -21)
	{
		color[0] = 237;
		color[1] = 44;
		color[2] = 219;
	}
	if (altitude >= -60 && altitude <= -41)
	{
		color[0] = 138;
		color[1] = 51;
		color[2] = 231;
	}
	else
		shading_colors4(color, altitude);
	return (color);
}

int			*shading_colors2(int *color, int altitude)
{
	if (altitude >= 41 && altitude <= 60)
	{
		color[0] = 56;
		color[1] = 219;
		color[2] = 75;
	}
	if (altitude >= 61 && altitude <= 80)
	{
		color[0] = 66;
		color[1] = 236;
		color[2] = 221;
	}
	if (altitude >= 81)
	{
		color[0] = 44;
		color[1] = 108;
		color[2] = 237;
	}
	else
		shading_colors3(color, altitude);
	return (color);
}

int			*shading_colors(int *color, int altitude)
{
	if (altitude == 0)
	{
		color[0] = 229;
		color[1] = 71;
		color[2] = 63;
	}
	if (altitude >= 1 && altitude <= 20)
	{
		color[0] = 232;
		color[1] = 211;
		color[2] = 60;
	}
	if (altitude >= 21 && altitude <= 40)
	{
		color[0] = 74;
		color[1] = 232;
		color[2] = 60;
	}
	else
		shading_colors2(color, altitude);
	return (color);
}
