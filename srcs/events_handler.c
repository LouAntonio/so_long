/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:38:51 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/21 12:40:36 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	player_up(t_game *game, t_point	player_position)
{
	if (game->map[player_position.x - 1][player_position.y] != '1')
		move_to_up(game, player_position);
}

void	player_left(t_game *game, t_point	player_position)
{
	if (game->map[player_position.x][player_position.y - 1] != '1')
		move_to_left(game, player_position);
}

void	player_down(t_game *game, t_point	player_position)
{
	if (game->map[player_position.x + 1][player_position.y] != '1')
		move_to_down(game, player_position);
}

void	player_right(t_game *game, t_point	player_position)
{
	if (game->map[player_position.x][player_position.y + 1] != '1')
		move_to_right(game, player_position);
}

int	key_press_handler(int keycode, t_game *game)
{
	t_point	player_position;

	player_position = get_player_position(game->map, 'P');
	if (keycode == 65307)
		close_game(game);
	else if (keycode == 65363 || keycode == 100)
		player_right(game, player_position);
	else if (keycode == 65361 || keycode == 97)
		player_left(game, player_position);
	else if (keycode == 65362 || keycode == 119)
		player_up(game, player_position);
	else if (keycode == 65364 || keycode == 115)
		player_down(game, player_position);
	return (0);
}
