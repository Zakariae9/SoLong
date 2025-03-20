#include "so_long.h"

char	**free_2d_a(char **str2a)
{
	int	i;

	i = 0;
	while (str2a[i])
	{
		free(str2a[i]);
		i++;
	}
	free(str2a);
	return (NULL);
}