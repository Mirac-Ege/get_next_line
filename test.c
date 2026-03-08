#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);

	// 1. ADIM: "Best\n" satırını oku
	line = get_next_line(fd);
	if (line)
	{
		// Satırın sonundaki \n (enter) karakterini basmamak için
		// sadece harfleri yazdırıyoruz.
		int i = 0;
		while (line[i] && line[i] != '\n')
		{
			write(1, &line[i], 1);
			i++;
		}
		free(line);
		write(1, " ", 1); // "Best"ten sonra bir boşluk atıyoruz
	}

	// 2. ADIM: "Of\n" satırını oku
	line = get_next_line(fd);
	if (line)
	{
		int i = 0;
		while (line[i] && line[i] != '\n')
		{
			write(1, &line[i], 1);
			i++;
		}
		free(line);
	}

	write(1, "\n", 1); // En son şık bir enter
	close(fd);
	return (0);
}
