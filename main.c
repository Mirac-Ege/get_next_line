/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 14:55:31 by mkotan            #+#    #+#             */
/*   Updated: 2026/04/21 19:04:26 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);

    // Tek bir fd üzerinden döngüyle oku
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line); // Belleği her seferinde boşalt!
    }
    close(fd);
    return (0);
}
