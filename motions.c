#include "so_long.h"

/*up = 65362
down = 65364
left = 65361
right = 65363
distroy window = 65307
*/

void	move_up(t_data *data)
{
	if (data->map.map[data->player.y - 1][data->player.x] == '1')
		return ;
	if (data->exit.x == data->player.x && data->exit.y == data->player.y)
		data->map.map[data->player.y][data->player.x] = 'E';
	else
		data->map.map[data->player.y][data->player.x] = '0';
	if (data->map.map[data->player.y - 1][data->player.x] == 'C')
		data->player.remaining_collectables--;
	data->map.map[--data->player.y][data->player.x] = 'P';
	if (data->exit.x == data->player.x && data->exit.y == data->player.y && !data->player.remaining_collectables)
		out_than_game(data, 0);
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(++data->moves_number, 1);
	ft_putstr_fd("\n", 1);
	display_map_on_window(data);
}

void	move_down(t_data *data)
{
	if (data->map.map[data->player.y + 1][data->player.x] == '1')
		return ;
	if (data->exit.x == data->player.x && data->exit.y == data->player.y)
		data->map.map[data->player.y][data->player.x] = 'E';
	else
		data->map.map[data->player.y][data->player.x] = '0';
	if (data->map.map[data->player.y + 1][data->player.x] == 'C')
		data->player.remaining_collectables--;
	data->map.map[++data->player.y][data->player.x] = 'P';
	if (data->exit.x == data->player.x && data->exit.y == data->player.y && !data->player.remaining_collectables)
		out_than_game(data, 0);
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(++data->moves_number, 1);
	ft_putstr_fd("\n", 1);
	display_map_on_window(data);

}
void	turn_left(t_data *data)
{
	if (data->map.map[data->player.y][data->player.x - 1] == '1')
		return ;
	if (data->exit.x == data->player.x && data->exit.y == data->player.y)
		data->map.map[data->player.y][data->player.x] = 'E';
	else
		data->map.map[data->player.y][data->player.x] = '0';
	if (data->map.map[data->player.y][data->player.x - 1] == 'C')
		data->player.remaining_collectables--;
	data->map.map[data->player.y][--data->player.x] = 'P';
	if (data->exit.x == data->player.x && data->exit.y == data->player.y && !data->player.remaining_collectables)
		out_than_game(data, 0);
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(++data->moves_number, 1);
	ft_putstr_fd("\n", 1);
	display_map_on_window(data);
}
void	turn_right(t_data *data)
{
	if (data->map.map[data->player.y ][data->player.x + 1] == '1')
		return ;
	if (data->exit.x == data->player.x && data->exit.y == data->player.y)
		data->map.map[data->player.y][data->player.x] = 'E';
	else
		data->map.map[data->player.y][data->player.x] = '0';
	if (data->map.map[data->player.y][data->player.x + 1] == 'C')
		data->player.remaining_collectables--;
	data->map.map[data->player.y][++data->player.x] = 'P';
	if (data->exit.x == data->player.x && data->exit.y == data->player.y && !data->player.remaining_collectables)
		out_than_game(data, 0);
	ft_putstr_fd("move : ", 1);
	ft_putnbr_fd(++data->moves_number, 1);
	ft_putstr_fd("\n", 1);
	display_map_on_window(data);
}

int	key_press(int key, t_data *data)
{
	if (key == 65307)
		out_than_game(data, 0);
	else if (key == e_down)
		move_down(data);
	else if (key == e_up)
		move_up(data);
	else if (key == e_right)
		turn_right(data);
	else if (key == e_left)
		turn_left(data);
	return (0);
}
