/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:03:23 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/21 12:35:27 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	show_player_moves(t_game *game)
{
	ft_putstr("Moves: ");
	ft_putnbr(game->qtt_moves);
	ft_putstr("\n");
}

void	exit_on_read(int fd)
{
	ft_putstr("Error\nInvalid map!\n");
	close(fd);
	exit(1);
}

void	exit_while_reading(int fd)
{
	ft_putstr("Error\nError while reading the map!\n");
	close(fd);
	exit(1);
}

int	close_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->batman);
	mlx_destroy_image(game->mlx, game->bat_left);
	mlx_destroy_image(game->mlx, game->batarang);
	mlx_destroy_image(game->mlx, game->mobile);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->rocks);
	mlx_destroy_window(game->mlx, game->mlx_w);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_matrix(game->map);
	exit(0);
	return (0);
}

void	finish_game(t_game *game)
{
	ft_putstr("Total moves: ");
	ft_putnbr(game->qtt_moves);
	ft_putstr("\n");
	mlx_destroy_image(game->mlx, game->batman);
	mlx_destroy_image(game->mlx, game->bat_left);
	mlx_destroy_image(game->mlx, game->batarang);
	mlx_destroy_image(game->mlx, game->mobile);
	mlx_destroy_image(game->mlx, game->grass);
	mlx_destroy_image(game->mlx, game->rocks);
	mlx_destroy_window(game->mlx, game->mlx_w);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_matrix(game->map);
	exit(0);
}
