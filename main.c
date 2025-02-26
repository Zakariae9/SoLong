#include "so_long.h"

int	num_lines(char *file_name)
{
	int	counter;
	int	fd;

	fd = open(file_name, O_CREAT | O_RDONLY, 0400);
	counter = 0;
	while (get_next_line(fd))
		counter++;
	close(fd);
	// printf("%d\n", counter);
	return (counter);
}

int main(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_CREAT | O_RDONLY, 0400);
    if (ac == 2 && fd != -1)
    {
		if (!ft_strcmp("map.ber", av[1]) || !check_is_map_valid(fd, av[1]))
		{
			close(fd);
			write(2, "Error\n", 6);
			return (1);
		}
    }
	close(fd);
    return (0);
}