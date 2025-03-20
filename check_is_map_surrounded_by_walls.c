#include "so_long.h"

int does_the_line_have_only1(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
		{
			return (0);
		}
        i++;
    }
    return (1);
}

int is_the_last_char_equal1(char *line)
{
    int len;

    len = ft_strlen(line);
    return (line[len - 1] == '1');
}

int is_map_surrounded_by_walls(t_data *data)
{
    int 	i;
	char	**old_2d;
	char	*str;

    i = 0;
	old_2d = data->map.map;
	str = join(data->map.map);
	data->map.map = ft_split(str, '\n');
	free(str);
	free_2d_a(old_2d);
    if (!does_the_line_have_only1(data->map.map[i]) || 
        !does_the_line_have_only1(data->map.map[data->map.num_lines - 1]))
        return (0);
    while (++i < data->map.num_lines)
    {
        if (data->map.map[i][0] != '1' || !is_the_last_char_equal1(data->map.map[i]))
            return (0);
    }
    return (1);
}
