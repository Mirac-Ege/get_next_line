#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Hata: Dosya acilamadi");
		return (1);
	}
	/* get_next_line cagrisi bir dongu icinde olmalidir [cite: 88] */
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line); /* Sızıntıyı önlemek için her satırı free ediyoruz  */
	}
    line = get_next_line(fd);
    printf("%s", line);
	/* Okunacak bir sey kalmadiginda GNL NULL doner  */
	close(fd);
	return (0);
}
