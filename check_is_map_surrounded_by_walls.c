#include "so_long.h"

int does_the_line_have_only1(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1')
            return (0);
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

int is_map_surrounded_by_walls(char **lines, int lines_number)
{
    int i;

    i = 0;
    if (!does_the_line_have_only1(lines[i]) || 
        !does_the_line_have_only1(lines[lines_number - 1]))
        return (0);
    while (--lines_number > 1)
    {
        i++;
        if (lines[i][0] != '1' || !is_the_last_char_equal1(lines[i]))
            return (0);
    }
    return (1);
}
