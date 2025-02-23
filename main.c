#include "so_long.h"

int main(int ac, char **av)
{
    if (ac == 2)
    {
		if (!check_map_is_correct(av + 1))
			return (1);
    }
    return (0);
}