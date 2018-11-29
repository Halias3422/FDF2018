/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/08 13:15:36 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/09 10:39:03 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int		a;

	a = 0;
	while (n > 0)
	{
		if (((unsigned char*)src)[a] == (unsigned char)c)
		{
			((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
			return (&dst[++a]);
		}
		((unsigned char*)dst)[a] = ((unsigned char*)src)[a];
		a++;
		n--;
	}
	return (NULL);
}
