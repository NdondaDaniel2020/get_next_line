# include "get_next_line.h"
# include <stdio.h>

// int	main(int ac, char **av)
int	main(void)
{
	int	fd1;
	// int	fd2;

	// (void)ac;
	// fd1 = open(av[1], O_RDONLY);
	// fd2 = open(av[2], O_RDONLY);
	fd1 = open("test/file3.txt", O_RDONLY);

	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd1));
	// printf("%s", get_next_line(fd2));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd1);
	// close(fd2);
	return (0);
}
