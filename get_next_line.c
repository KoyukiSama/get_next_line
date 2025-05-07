/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 14:36:52 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/07 18:00:30 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

char		*ft_stash_init(t_stash *stash);
char		*ft_stash_append(t_stash *stash, const char *buff);
char		*ft_buff_read(char *buff, int fd);
char		*ft_clean_exit(t_stash *stash);
char		*ft_stash_get_line(t_stash *stash);
int			ft_needs_fill(t_stash *t_stash);
char		*ft_stash_fill(int fd, t_stash *stash);
static char	*ft_malloc_line(size_t line_ln);

#include <stdio.h>
char	*get_next_line(int fd)
{
	static t_stash	stash_arr[OPEN_MAX] = {0};
	char			*ret_line;

	if (BUFF_SIZE <= 0 || fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!ft_stash_init(&stash_arr[fd]))
		return (NULL);
	if (&stash_arr[fd].stash == &stash_arr[fd].stash_strt_ptr
		|| ft_needs_fill(&stash_arr[fd]))
	{
		if (!ft_stash_fill(fd, &stash_arr[fd]))
			return (ft_clean_exit(&stash_arr[fd]));
	}
	ret_line = ft_stash_get_line(&stash_arr[fd]);
	return (ret_line);
}

char	*ft_stash_fill(int fd, t_stash *stash)
{
	char	*buff;
	
	buff = malloc(BUFF_SIZE + 1);
	if (!buff)
		return (free(buff), ft_clean_exit(stash));
	while (ft_needs_fill(stash))
	{
		if (!ft_buff_read(buff, fd))
			return (free(buff), NULL);
		if (buff[0] == '\0')
			break;
		if (!ft_stash_append(stash, buff))
			return (free(buff), NULL);
	}
	free(buff);
	return (stash->stash);
}

char	*ft_buff_read(char *buff, int fd)
{
	ssize_t	bytes_read;
	
	bytes_read = read(fd, buff, BUFF_SIZE);
	if (bytes_read == -1)
		return (free(buff), NULL);
	buff[bytes_read] = '\0';
	return (buff);
}

int	ft_needs_fill(t_stash *t_stash)
{
	size_t	i;

	i = 0;
	while (t_stash->stash[i] != '\n' && t_stash->stash[i] != '\0')
		i++;
	if (t_stash->stash[i] == '\0')
		return (1);
	return (0);
}

char	*ft_stash_get_line(t_stash *stash)
{
	char	*line;
	size_t	i;

	i = 0;
	fprintf(stderr, _GREEN"%i "_RESET, stash->stash[i]);
	while (stash->stash[i] != '\n' && stash->stash[i] != '\0')
		i++;
	if (stash->stash[i] == '\n')
		i++;
	line = ft_malloc_line(i);
	if (!line)
		ft_clean_exit(stash);
	i = 0;
	while (stash->stash[i] != '\n' && stash->stash[i] != '\0')
	{
		line[i] = stash->stash[i];
		i++;
	}
	line[i] = '\0';
	if (*stash->stash == '\0')
		return(ft_clean_exit(stash), line);
	stash->stash += i;
	return (line);
}

static char	*ft_malloc_line(size_t line_ln)
{
	if (line_ln == 0)
		return (NULL);
	return (malloc(line_ln + 1));
}
