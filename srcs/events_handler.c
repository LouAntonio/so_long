/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:38:51 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/13 18:41:01 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_up(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');
	if (vars->map[player_position.x - 1][player_position.y] != '1')
		move_to_up(vars);
}
void	player_left(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');
	if (vars->map[player_position.x][player_position.y - 1] != '1')
		move_to_left(vars);
}
void	player_down(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');
	if (vars->map[player_position.x + 1][player_position.y] != '1')
		move_to_down(vars);
}
void	player_right(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');
	if (vars->map[player_position.x][player_position.y + 1] != '1')
		move_to_right(vars);
}

int	key_press_handler(int keycode, t_game *vars)
{
	if (keycode == 65307){
		mlx_destroy_window(vars->mlx, vars->mlx_w);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
		return (0);
	}
	else if (keycode == 65363)
		player_right(vars);
	else if (keycode == 65361)
		player_left(vars);
	else if (keycode == 65362)
		player_up(vars);
	else if (keycode == 65364)
		player_down(vars);
}
