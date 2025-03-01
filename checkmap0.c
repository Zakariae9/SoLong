#include "so_long.h"

char	**read_lines(int fd, int count_lines)
{
	char	**lines;
	char	*line;
	char	**oreginal_line;
	int		i;
	
	lines = malloc(sizeof(char *) * (count_lines + 1));
	i = 0;
	while (1)
	{
		lines[i] = get_next_line(fd);
		if (!lines[i])
			break ;
		i++;
	}
	line = join(lines);
	oreginal_line = ft_split(line, '\n');
	free_2d_a(lines);
	free(line);
	return (oreginal_line);
}

int	is_there_anything_else(char **lines)
{
	int		i;
	int		j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (!ft_strchr("01ECP", lines[i][j]))
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

int	check_is_map_valid(int fd, char *file_name)
{
	char	**lines;
	int		result;
	
	int		(num_of_lines) = num_lines(file_name);
	lines = read_lines(fd, num_of_lines);
	result = (are_all_lines_have_same_len(lines) 
		&& !is_there_anything_else(lines) && are_components_correct(lines)
		 && is_map_surrounded_by_walls(lines, num_of_lines));
	free_2d_a(lines);
	return (result);
}