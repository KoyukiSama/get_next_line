/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kclaes <kclaes@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/05/02 15:10:47 by kclaes        #+#    #+#                 */
/*   Updated: 2025/05/02 17:59:52 by kclaes        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static size_t	ft_strlen(const char *str);
static char		*ft_stash_append_helpr(char *stash_new, char *stash_old, \
									const char *buff);

// if (stash_old is NULL) ~ starting condition,
// it will create an empty ft_strempty
char	*ft_stash_append(char *stash_old, const char *buff)
{
	char	*stash_new;
	
	if (!stash_old)
	{
		stash_old = malloc(1);
		if (!stash_old)
			return (NULL);
		*stash_old = '\0';
		if (!stash_old)
			return (NULL);
	}
	stash_new = malloc(ft_strlen(stash_old) + ft_strlen(buff) + 1);
	if (!stash_new)
		return (free(stash_old), NULL);
	return (ft_stash_append_helpr(stash_new, stash_old, buff));
}

static char	*ft_stash_append_helpr(char *stash_new, char *stash_old, \
								const char *buff)
{
	size_t	i;
	size_t	j;
	
	i = 0;
	j = 0;
	while (stash_old[j])
		stash_new[i++] = stash_old[j++];
	j = 0;
	while (buff[j])
		stash_new[i++] = buff[j++];
	stash_new[i] = '\0';
	free(stash_old);
	return (stash_new);
}

static size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len])
		str_len++;
	return (str_len);
}
