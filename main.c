#include "so_long.h"

int	copy_map(t_map *map)
{
	int		y;

	map->cpy_map = malloc(sizeof(char *) * (map->num_lines + 1));
	if (!map->cpy_map)
		return (0);
	y = -1;
	while (++y < map->num_lines)
		map->cpy_map[y] = ft_strdup(map->map[y]);
	map->cpy_map[y] = NULL;
	return (1);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (map->cpy_map[y][x] == '1' && (x <= map->width && x >= 0) && (y <= map->num_lines && x >= 0))
		return ;
	map->cpy_map[y][x] = '1';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_flood_fill(t_data *data)
{
	int	i;

	i = 0;
	if (!copy_map(&data->map))
		return (0);
	get_position_of_tile(data, &data->player.x, &data->player.y,'P');
	flood_fill(&data->map, data->player.x, data->player.y);
	while (i++ < data->map.height)
	{
		if (is_there_anything_else(data->map.cpy_map, "1"))
		{
			data->map.cpy_map = free_2d_a(data->map.cpy_map);
			return (0);
		}
	}
	data->map.cpy_map = free_2d_a(data->map.cpy_map);
	return (1);
}

int	num_lines(char *file_name)
{
	int		counter;
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	counter = 0;
	while ((line = get_next_line(fd)))
	{
		counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

int main(int ac, char **av)
{
	int		fd;
	t_data	data;
	
	fd = 0;
	data = (t_data){0};
	if (ac != 2 || !check_file_name(av[1]) || !check_is_map_valid(&fd, av[1], &data))
		get_out(&fd, av[1]);
	data.map.file_name = av[1];
	start_work(&fd, &data);
	mlx_loop(data.mlx);
    return (0);
}
