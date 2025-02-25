#include "so_long.h"

int is_one_of_components_missing(char **lines)
{
    int     i;
    int     j;
    int     is_there;
    char    *components;

    i = - 1;
    components = "10ECP";
    while (lines[++i])
    {
        j = 0;
        while (lines[i][j])
        {
            if (!ft_strchr(lines[i], components[i]))
                is_there = 0;
            else
            {
                is_there = 1;
                break ;
            }
        }
        if (!is_there)
            return (1);
    }
    return (0);
}

int count_char_duplicates(char **lines, char c)
{
    int i;
    int j;
    int counter;

    counter = 0;
	i = 0;
    while (lines[i])
	{
		j = 0;
		while (lines[i][j])
		{
			if (ft_strchr(lines[i], c))
				counter++;	
		}
		i++;
	}
	return (counter);
}

int are_components_correct(char **lines)
{
    if (is_one_of_components_missing(lines))
        return (0);
	if (count_char_duplicates(lines, 'E') != 1)
		return (0);
	if (count_char_duplicates(lines, 'C') < 1)
		return (0);
	if (count_char_duplicates(lines, 'P') != 1)
		return (0);
	return (1);
}
