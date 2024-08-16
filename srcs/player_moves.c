/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:44 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/16 11:48:54 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_to_up(t_game *vars, t_point player_position)
{
	if (vars->map[player_position.x - 1][player_position.y] == 'E'
		&& char_validator(vars->map, 'C'))
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	else if (vars->map[player_position.x - 1][player_position.y] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	if (vars->map[player_position.x - 1][player_position.y] == 'C')
	{
		vars->map[player_position.x - 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
	}
	if (vars->map[player_position.x - 1][player_position.y] == '0')
	{
		vars->map[player_position.x - 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
	}
}

void	move_to_down(t_game *vars, t_point player_position)
{
	if (vars->map[player_position.x + 1][player_position.y] == 'E'
		&& char_validator(vars->map, 'C'))
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	else if (vars->map[player_position.x + 1][player_position.y] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	if (vars->map[player_position.x + 1][player_position.y] == 'C')
	{
		vars->map[player_position.x + 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
	}
	if (vars->map[player_position.x + 1][player_position.y] == '0')
	{
		vars->map[player_position.x + 1][player_position.y] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
	}
}

void	move_to_left(t_game *vars, t_point player_position)
{
	vars->player = vars->b_b;
	if (vars->map[player_position.x][player_position.y - 1] == 'E'
		&& char_validator(vars->map, 'C'))
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	else if (vars->map[player_position.x][player_position.y - 1] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	if (vars->map[player_position.x][player_position.y - 1] == 'C')
	{
		vars->map[player_position.x][player_position.y - 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
	}
	if (vars->map[player_position.x][player_position.y - 1] == '0')
	{
		vars->map[player_position.x][player_position.y - 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		map_render(*vars);
	}
}

void	move_to_right(t_game *vars, t_point player_position)
{
	if (vars->map[player_position.x][player_position.y + 1] == 'E'
		&& char_validator(vars->map, 'C'))
		ft_putstr("YOU NEED TO CATH ALL THE COLLECTIBLES BEFORE LEAVE\n");
	else if (vars->map[player_position.x][player_position.y + 1] == 'E'
		&& !char_validator(vars->map, 'C'))
		finish_game(vars);
	if (vars->map[player_position.x][player_position.y + 1] == 'C')
	{
		vars->map[player_position.x][player_position.y + 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->player = vars->batman;
		map_render(*vars);
	}
	if (vars->map[player_position.x][player_position.y + 1] == '0')
	{
		vars->map[player_position.x][player_position.y + 1] = 'P';
		vars->map[player_position.x][player_position.y] = '0';
		vars->player = vars->batman;
		map_render(*vars);
	}
}
