# ifndef SO_LONG_H
# define SO_LONG_H

#include "/usr/include/minilibx-linux/mlx.h"
#include "current_line/get_next_line.h"
#include "libft1/libft.h"

typedef struct st_map
{
	char	*file_name;
	char	**map;
	char	**cpy_map;
	int		height;
	int		width;
	int		num_lines;
}t_map ;

typedef struct st_exit
{
	int y;
	int	x;
}t_exit;

typedef struct st_player
{
	int y;
	int	x;
	int	remaining_collectables;
}t_player;

typedef struct st_data
{
	void		*mlx;
	void		*window;
	int			helper_width;
	int			helper_height;
	void		*player_img;
	void		*exit_img;
	void		*wall_img;
	void		*ground_img;
	void		*collictable_img;
	int			moves_number;
	t_map		map;
	t_player	player;
	t_exit		exit;
}t_data ;

enum	en_moves{e_left = 65361, e_right = 65363, e_up = 65362, e_down = 65364};

int		check_is_map_valid(int *fd, char *file_name, t_data *data);
char	**read_lines(int fd, int count_lines, t_map *map);
int		are_all_lines_have_same_len(char **lines);
int	    are_all_lines_have_same_len(char **lines);
int     is_there_anything_else(char **lines, char *str_to_check);
int     are_components_correct(char **lines);
int     count_char_duplicates(char **lines, char c);
int     is_one_of_components_missing(char **lines);
int     is_map_surrounded_by_walls(t_data *data);
int     is_the_last_char_equal1(char *line);
int     does_the_line_have_only1(char *line);
char	**free_2d_a(char **str2a);
int		num_lines(char *file_name);
char	*join(char **s);
void	print_map(t_data *data);
void	display_map_on_window(t_data *data);
void	start_work(int *fd, t_data *data);
void	get_out(int *fd, char *map);
void	revivel_fd(int *fd, char *file_name);
void	out_than_game(t_data *data, int status);
int		key_press(int key, t_data *data);
void	motions(t_data *data);
void	get_position_of_tile(t_data *data, int *x, int *y, char tile);
void	move_up(t_data *data);
void	move_down(t_data *data);
void	turn_left(t_data *data);
void	turn_right(t_data *data);
void	count_collectables(t_data *data);
void	fill_images(t_data *data);
int		check_file_name(char *file_name);
int		x_window(t_data *data);
void	free_images(t_data *data);
int		check_flood_fill(t_data *data);
void	flood_fill(t_map *map, int x, int y);
int		copy_map(t_map *map);





# endif