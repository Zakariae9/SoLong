# ifndef SO_LONG_H
# define SO_LONG_H

#include "current_line/get_next_line.h"
#include "libft1/libft.h"
#include <stdio.h>

int		check_is_map_valid(int fd, char *file_name);
char	**read_lines(int fd, int count_lines);
int		are_all_lines_have_same_len(char **lines);
int	    are_all_lines_have_same_len(char **lines);
int     is_there_anything_else(char **lines);
int     are_components_correct(char **lines);
int     count_char_duplicates(char **lines, char c);
int     is_one_of_components_missing(char **lines);
int     is_map_surrounded_by_walls(char **lines, int lines_number);
int     is_the_last_char_equal1(char *line);
int     does_the_line_have_only1(char *line);
char	*free_2d_a(char **str2a);
int		num_lines(char *file_name);

# endif