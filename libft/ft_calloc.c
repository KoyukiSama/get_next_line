/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/23 23:02:25 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/01 18:32:57 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t n, size_t size)
{
	size_t	bytes;
	void	*s;

	if (n > SIZE_MAX / size)
		return (NULL);
	bytes = n * size;
	s = malloc(bytes);
	if (!s)
		return (NULL);
	return (ft_memset(s, 0, bytes));
}
