#include "so_long.h"

int is_one_of_components_missing(char **lines)
{
    int     i;
    int     j;
    int     is_there;
    char    *components;

    i = - 1;
    components = "10ECP";
    while (components[++i])
    {
		j = -1;
		is_there = 0;
        while (lines[++j])
        {
            if (ft_strchr(lines[j], components[i]))
			{
				is_there = 1;
				break ;
			}
        }
   	}
	return (!is_there);
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
			if (lines[i][j++] == c)
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
	else if (count_char_duplicates(lines, 'E') != 1)
		return (0);
	else if (count_char_duplicates(lines, 'C') < 1)
		return (0);
	else if (count_char_duplicates(lines, 'P') != 1)
		return (0);
	return (1);
}
