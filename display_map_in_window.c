#include "so_long.h"

void	count_collectables(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.map[y][x] == 'C')
				data->player.remaining_collectables++;
			x++;
		}
		y++;
	}
}

void	fill_images(t_data *data)
{
	data->collictable_img = mlx_xpm_file_to_image(data->mlx, "textures/collectable.xpm", &data->helper_width, &data->helper_height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm", &data->helper_width, &data->helper_height);
	data->ground_img = mlx_xpm_file_to_image(data->mlx, "textures/ground.xpm", &data->helper_width, &data->helper_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm", &data->helper_width, &data->helper_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm", &data->helper_width, &data->helper_height);
}

void	display_map_on_window(t_data *data)
{
	int x;
	int	y;

	y = 0;
	while (y < data->map.height)
        {
                x = 0;
                while (x < data->map.width)
                {
					if (data->map.map[y][x] == 'P')
						mlx_put_image_to_window(data->mlx, data->window, data->player_img, x * 64, y * 64);
					else if (data->map.map[y][x] == 'C')
						mlx_put_image_to_window(data->mlx, data->window, data->collictable_img, x * 64, y * 64);
					else if (data->map.map[y][x] == 'E')
						mlx_put_image_to_window(data->mlx, data->window, data->exit_img, x * 64, y * 64);
					else if (data->map.map[y][x] == '0')
						mlx_put_image_to_window(data->mlx, data->window, data->ground_img, x * 64, y * 64);
					else if (data->map.map[y][x] == '1')
						mlx_put_image_to_window(data->mlx, data->window, data->wall_img, x * 64, y * 64);

					x++;
                }
                y++;
        }
}

void	print_map(t_data *data)
{
	count_collectables(data);
	data->mlx = mlx_init();
	if (!data->mlx)
		out_than_game(data, 1);
	if (!data->window)
		data->window = mlx_new_window(data->mlx, 64 * (data->map.width), 64 * data->map.height, "so_long");
	fill_images(data);
	display_map_on_window(data);
}
