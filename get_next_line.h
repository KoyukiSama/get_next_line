/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:26:20 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 16:44:50 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE BUFFER_SIZE

// stash_strt_ptr is the malloc pointer
// stash is a modified ptr
typedef struct s_stash
{
	char	*stash;
	char	*stash_strt_ptr;
}	t_stash;

char	*get_next_line(int fd);
char	*ft_stash_append(char *stash_old, const char *buff);
char	*ft_stash_get_line(t_stash *stash);
char	*ft_stash_fill(int fd, char *stash);
void	ft_stash_free(t_stash *stash);

#endif