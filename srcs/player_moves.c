/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:44 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/21 12:20:55 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_to_up(t_game *vars, t_point player_position)
{
	if (vars->map[player_position.x - 1][player_position.y] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	else if (vars->map[player_position.x - 1][player_position.y] == 'C')
	{
		vars->map[player_position.x - 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
	else if (vars->map[player_position.x - 1][player_position.y] == '0')
	{
		vars->map[player_position.x - 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
}

void	move_to_down(t_game *vars, t_point player_position)
{
	if (vars->map[player_position.x + 1][player_position.y] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	else if (vars->map[player_position.x + 1][player_position.y] == 'C')
	{
		vars->map[player_position.x + 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
	else if (vars->map[player_position.x + 1][player_position.y] == '0')
	{
		vars->map[player_position.x + 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
}

void	move_to_left(t_game *vars, t_point player_position)
{
	vars->player = vars->bat_left;
	if (vars->map[player_position.x][player_position.y - 1] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	else if (vars->map[player_position.x][player_position.y - 1] == 'C')
	{
		vars->map[player_position.x][player_position.y - 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
	else if (vars->map[player_position.x][player_position.y - 1] == '0')
	{
		vars->map[player_position.x][player_position.y - 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
}

void	move_to_right(t_game *vars, t_point player_position)
{
	vars->player = vars->batman;
	if (vars->map[player_position.x][player_position.y + 1] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	else if (vars->map[player_position.x][player_position.y + 1] == 'C')
	{
		vars->map[player_position.x][player_position.y + 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
	else if (vars->map[player_position.x][player_position.y + 1] == '0')
	{
		vars->map[player_position.x][player_position.y + 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->qtt_moves++;
		show_player_moves(vars);
		map_render(*vars);
	}
}
