#include "so_long.h"

int main(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_CREAT | O_RDONLY, 0400);
    if (ac == 2 && fd != -1)
    {
		if (!check_is_map_valid(fd, av[1]))
		{
			write(2, "Error\n", 6);
			return (1);
		}
    }
    return (0);
}