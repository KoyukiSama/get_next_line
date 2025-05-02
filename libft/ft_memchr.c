/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/27 18:40:19 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	The  memchr()  and  memrchr()
//	functions return a pointer to
//	the matching byte or NULL  if
//	the  character does not occur
//	in the given memory area.	 (from man page memchr)
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *) s;
	uc = (unsigned char) c;
	while (n--)
	{
		if (*us == uc)
			return ((void *) us);
		us++;
	}
	return (NULL);
}
