#include "so_long.h"

char	**read_lines(int fd, int count_lines, t_map *map)
{
	int		i;
	char	*temp;
	
	map->height = count_lines;
	map->map = malloc(sizeof(char *) * (count_lines + 1));
	if (!map->map)
		return (NULL);
	i = 0;
	while (1)
	{
		map->map[i] = get_next_line(fd);
		if (!map->map[i])
		{
			temp = map->map[i - 1];
			map->map[i - 1] = ft_strjoin(map->map[i - 1],"\n" );
			if (!map->map[i - 1])
				free_2d_a(map->map);
			free(temp);
			break ;
		}
		i++;
	}
	return (map->map);
}

int	is_there_anything_else(char **lines, char *str_to_check)
{
	int		i;
	int		j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!ft_strchr(str_to_check, lines[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	are_all_lines_have_same_len(char **lines)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(lines[i]);
	while (lines[i])
	{
		if (len != ft_strlen(lines[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_is_map_valid(int *fd, char *file_name, t_data *data)
{
	int		result;

	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		return (0);
	data->map.num_lines = num_lines(file_name);
	read_lines(*fd, data->map.num_lines, &data->map);
	if (!data->map.map)
		return (0);
	data->map.width = ft_strlen(data->map.map[0]) - 1;
	result = (are_all_lines_have_same_len(data->map.map) 
		&& !is_there_anything_else(data->map.map, "\n10PCE") && are_components_correct(data->map.map)
		 && is_map_surrounded_by_walls(data) && check_flood_fill(data));
	if (result == 0)
		free_2d_a(data->map.map);
	return (result);
}

int	check_file_name(char *file_name)
{
	if (!ft_strcmp(ft_strrchr(file_name, '.'), ".ber") && !ft_strncmp("maps/", file_name, 5))
	{
		if (ft_strcmp(ft_strrchr(file_name, '/'), "/.ber"))
			return (1);
	}
	return (0);	
}