#include "so_long.h"

char	**read_lines(int fd, int *count_lines)
{
	char	**lines;
	int		i;
	int		len;

	i = 0;
	lines[i] = "";
	while (lines[i])
	{
		len = ft_strlen((lines[i] = get_next_line(fd)));
		ft_strlcpy(lines[i], lines[i], len - 2);
		i++;
		*(count_lines++);	
	}
	lines[i] = NULL;
	return (lines);
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
	int	i;
	int	len;

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

int	does_path_of_map_valid(char *file_name)
{
	char	*extension;

	extension = ft_strrchr(file_name, '.');
	if (!extension)
		return (0);
	return (ft_strncmp(extension, ".ber", ft_strlen(extension)) == 0);
}

int	check_is_map_valid(int fd, char *file_name)
{
	char	**lines;
	int		num_lines;

	num_lines = 0;
	lines = read_lines(fd, &num_lines);
	return (!does_path_of_map_valid(file_name) || !are_all_lines_have_same_len(lines) 
		|| is_there_anything_else(lines) || is_one_of_components_missing(lines) 
		|| are_components_correct(lines) || is_map_surrounded_by_walls(lines, num_lines));
}