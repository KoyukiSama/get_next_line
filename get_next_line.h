/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:26:20 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/10 14:25:10 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  define BUFF_SIZE BUFFER_SIZE
# else
#  define BUFF_SIZE 42
# endif
# define OPEN_MAX 1024

// stash_strt_ptr is the malloc pointer
// stash is a modified ptr
typedef struct s_stash
{
	char	*stash;
	char	*stash_strt_ptr;
}	t_stash;

char	*get_next_line(int fd);

#endif