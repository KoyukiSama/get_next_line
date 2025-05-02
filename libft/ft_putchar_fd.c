/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/28 19:38:26 by kclaes        #+#    #+#                 */
/*   Updated: 2025/04/28 21:12:02 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
