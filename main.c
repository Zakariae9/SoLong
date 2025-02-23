#include "so_long.h"

int main(int ac, char **av)
{
	int	fd;

	fd = open(av[1], O_CREAT | O_RDONLY, 0400);
    if (ac == 2 && fd != -1)
    {
		if (!check_map_is_correct(fd, av + 1))
			return (1);
    }
    return (0);
}