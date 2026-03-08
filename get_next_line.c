/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 21:11:21 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/07 00:18:13 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buffer;
	char		*temp;
	int			read_byte;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	if (!stash)
		stash = ft_strdup("");
	while (!ft_strchr(stash, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[read_byte] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	if (!stash || !*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	while (stash[i] && stash[i] != '\n')
		i++;
	line = ft_substr(stash, 0, i + (stash[i] == '\n'));
	if (stash[i] == '\0')
		temp = NULL;
	else
		temp = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	stash = temp;
	return (line);
}
