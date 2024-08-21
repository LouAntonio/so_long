/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:04:44 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/21 12:36:34 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_to_up(t_game *game, t_point player_position)
{
	if (game->map[player_position.x - 1][player_position.y] == 'E'
		&& !char_validator(game->map, 'C'))
		finish_game(game);
	else if (game->map[player_position.x - 1][player_position.y] == 'C')
	{
		game->map[player_position.x - 1][player_position.y] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
	else if (game->map[player_position.x - 1][player_position.y] == '0')
	{
		game->map[player_position.x - 1][player_position.y] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
}

void	move_to_down(t_game *game, t_point player_position)
{
	if (game->map[player_position.x + 1][player_position.y] == 'E'
		&& !char_validator(game->map, 'C'))
		finish_game(game);
	else if (game->map[player_position.x + 1][player_position.y] == 'C')
	{
		game->map[player_position.x + 1][player_position.y] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
	else if (game->map[player_position.x + 1][player_position.y] == '0')
	{
		game->map[player_position.x + 1][player_position.y] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
}

void	move_to_left(t_game *game, t_point player_position)
{
	game->player = game->bat_left;
	if (game->map[player_position.x][player_position.y - 1] == 'E'
		&& !char_validator(game->map, 'C'))
		finish_game(game);
	else if (game->map[player_position.x][player_position.y - 1] == 'C')
	{
		game->map[player_position.x][player_position.y - 1] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
	else if (game->map[player_position.x][player_position.y - 1] == '0')
	{
		game->map[player_position.x][player_position.y - 1] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
}

void	move_to_right(t_game *game, t_point player_position)
{
	game->player = game->batman;
	if (game->map[player_position.x][player_position.y + 1] == 'E'
		&& !char_validator(game->map, 'C'))
		finish_game(game);
	else if (game->map[player_position.x][player_position.y + 1] == 'C')
	{
		game->map[player_position.x][player_position.y + 1] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
	else if (game->map[player_position.x][player_position.y + 1] == '0')
	{
		game->map[player_position.x][player_position.y + 1] = 'P';
		game->map[player_position.x][player_position.y] = '0';
		game->qtt_moves++;
		show_player_moves(game);
		map_render(*game);
	}
}
