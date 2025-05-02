/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:26:20 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/02 17:45:38 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE BUFFER_SIZE
# ifndef EOF
#  define EOF -1
# endif

char	*get_next_line(int fd);
char	*ft_stash_append(char *stash_old, const char *buff);

#endif