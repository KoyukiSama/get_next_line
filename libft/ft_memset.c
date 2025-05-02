/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/27 18:39:18 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*us;
	unsigned char	uc;

	us = (unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		*us++ = uc;
	}
	return (s);
}
