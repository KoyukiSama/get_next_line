/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:36:52 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/03 16:48:36 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char		*ft_stash_append(char *stash_old, const char *buff);
static char	*ft_stash_get_line(t_stash *stash);
static char	*ft_stash_fill(int fd, char *stash);
static void	ft_stash_free(t_stash *stash);
static char	*ft_malloc_line(size_t line_ln);

char	*get_next_line(int fd)
{
	static t_stash	*stash_arr[_SC_OPEN_MAX];
	char			*ret_line;
}

static char	*ft_stash_get_line(t_stash *stash)
{
	size_t	line_ln;
	char	*line;
	size_t	i;

	line_ln = 0;
	while ((*stash).stash[line_ln] != '\n' && (*stash).stash[line_ln] != '\0')
		line_ln++;
	if ((*stash).stash[line_ln] == '\n')
		line_ln++;
	line = ft_malloc_line(line_ln);
	if (!line)
		return (NULL);
	i = 0;
	while (i < line_ln)
	{
		line[i] = (*stash).stash[i];
		i++;
	}
	line[i] = '\0';
	if ((*stash).stash[i - 1] == '\n')
		ft_stash_free(stash);
	else
		(*stash).stash = (*stash).stash + i + 1;
	return (line);
}

// read into buffer
static char	*ft_stash_fill(int fd, char *stash)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 0;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFF_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		buff[bytes_read] = '\0';
		ft_stash_append(stash, buff);
	}
}

static void	ft_stash_free(t_stash *stash)
{
	free((*stash).stash_strt_ptr);
	(*stash).stash = NULL;
	(*stash).stash_strt_ptr = NULL;
}

static char	*ft_malloc_line(size_t line_ln)
{
	if (line_ln == 0)
		return (NULL);
	return (malloc(line_ln + 1));
}
