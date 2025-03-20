#include "so_long.h"

// void	revivel_fd(int *fd, char *file_name)
// {
// 	close(*fd);
// 	*fd = open(file_name, O_RDONLY, 0400); // ?
// 	if (*fd == -1)
// 		return ;
// }

void  get_position_of_tile(t_data *data, int *x, int *y, char tile)
{
	int	colum;
	int	row;

	row = 0;
	while (row < data->map.height)
	{
		*x = 0;
		colum = 0;
		while (colum < data->map.width)
		{
			if (data->map.map[row][colum] == tile)
				return ;
			++(*x);
			colum++;
		}
		(*y)++;
		row++;
	}	
}

int	x_window(t_data *data)
{
	out_than_game(data, 0);
	return (0);
}

void	motions(t_data *data)
{
	get_position_of_tile(data, &data->exit.x, &data->exit.y, 'E');
	mlx_hook(data->window, 2, 1L, &key_press, data);
	mlx_hook(data->window, 17, 0, &x_window, data);
}

void	start_work(int *fd, t_data *data)
{
	print_map(data);
	close(*fd);
	motions(data);
}