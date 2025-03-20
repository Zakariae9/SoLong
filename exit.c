#include "so_long.h"

void	free_images(t_data *data)
{
	if (data->collictable_img)
		mlx_destroy_image(data->mlx, data->collictable_img);
	if (data->exit_img)
		mlx_destroy_image(data->mlx, data->exit_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx, data->wall_img);
	if (data->ground_img)
		mlx_destroy_image(data->mlx, data->ground_img);
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
}

void	out_than_game(t_data *data, int status)
{
	free_2d_a(data->map.map);
	free_images(data);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (status)
		exit(1);
	exit(0);
}

void	get_out(int *fd, char *file_name)
{
	if (!file_name)
	{
		ft_putstr_fd("Error\nPlease enter name of file\n", 2);
		exit(1);	
	}
	if (*fd != -1)
		close(*fd);
	ft_putstr_fd("Error\nSome thing is error\n", 2);
	exit(1);
}
