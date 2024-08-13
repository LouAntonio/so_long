/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:44 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/13 18:57:00 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	finish_game(t_game *vars)
{
	ft_putstr("FINISH\n");
	mlx_destroy_window(vars->mlx, vars->mlx_w);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

void	move_to_up(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');

	if (vars->map[player_position.x - 1][player_position.y] == 'E'
		&& char_validator(vars->map, 'C')){
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	} else if (vars->map[player_position.x - 1][player_position.y] == 'E'
		&& !char_validator(vars->map, 'C')) {
		finish_game(vars);
	}
	if (vars->map[player_position.x - 1][player_position.y] == 'C'){
		vars->map[player_position.x - 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
		ft_putstr("UP\n");
	}
	if (vars->map[player_position.x - 1][player_position.y] == '0'){
		vars->map[player_position.x - 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
		ft_putstr("UP\n");
	}
}
void	move_to_down(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');

	if (vars->map[player_position.x + 1][player_position.y] == 'E'
		&& char_validator(vars->map, 'C')){
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	} else if (vars->map[player_position.x + 1][player_position.y] == 'E'
		&& !char_validator(vars->map, 'C')) {
		finish_game(vars);
	}
	if (vars->map[player_position.x + 1][player_position.y] == 'C'){
		vars->map[player_position.x + 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
		ft_putstr("DOWN\n");
	}
	if (vars->map[player_position.x + 1][player_position.y] == '0'){
		vars->map[player_position.x + 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
		ft_putstr("DOWN\n");
	}
}
void	move_to_left(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');

	if (vars->map[player_position.x][player_position.y - 1] == 'E'
		&& char_validator(vars->map, 'C')){
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	} else if (vars->map[player_position.x][player_position.y - 1] == 'E'
		&& !char_validator(vars->map, 'C')) {
		finish_game(vars);
	}
	if (vars->map[player_position.x][player_position.y - 1] == 'C'){
		vars->map[player_position.x][player_position.y - 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->player = vars->batman_left;
		map_render(*vars);
		ft_putstr("LEFT\n");
	}
	if (vars->map[player_position.x][player_position.y - 1] == '0'){
		vars->map[player_position.x][player_position.y - 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->player = vars->batman_left;
		map_render(*vars);
		ft_putstr("LEFT\n");
	}
}
void	move_to_right(t_game *vars)
{
	t_point player_position = get_char_position(vars->map, 'P');

	if (vars->map[player_position.x][player_position.y + 1] == 'E'
		&& char_validator(vars->map, 'C')){
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	} else if (vars->map[player_position.x][player_position.y + 1] == 'E'
		&& !char_validator(vars->map, 'C')) {
		finish_game(vars);
	}
	if (vars->map[player_position.x][player_position.y + 1] == 'C'){
		vars->map[player_position.x][player_position.y + 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->player = vars->batman;
		map_render(*vars);
		ft_putstr("RIGHT\n");
	}
	if (vars->map[player_position.x][player_position.y + 1] == '0'){
		vars->map[player_position.x][player_position.y + 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->player = vars->batman;
		map_render(*vars);
		ft_putstr("RIGHT\n");
	}
}