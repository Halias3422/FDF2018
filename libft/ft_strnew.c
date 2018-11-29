/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/04 17:44:55 by vde-sain     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/15 15:46:49 by vde-sain    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;
	size_t	a;

	a = 0;
	if (!(dest = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (a <= size)
		dest[a++] = '\0';
	return (dest);
}
