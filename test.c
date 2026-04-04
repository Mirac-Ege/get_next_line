/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 14:50:14 by mkotan            #+#    #+#             */
/*   Updated: 2026/04/04 14:50:15 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		i;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	write(1, "\n", 1);
	return (0);
}
