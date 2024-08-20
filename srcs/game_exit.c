/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:03:23 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/20 12:09:45 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

int	close_game(t_game *vars)
{
	mlx_destroy_image(vars->mlx, vars->batman);
	mlx_destroy_image(vars->mlx, vars->b_b);
	mlx_destroy_image(vars->mlx, vars->batarang);
	mlx_destroy_image(vars->mlx, vars->mobile);
	mlx_destroy_image(vars->mlx, vars->grass);
	mlx_destroy_image(vars->mlx, vars->rocks);
	mlx_destroy_window(vars->mlx, vars->mlx_w);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_matrix(vars->map);
	exit(0);
	return (0);
}

void	finish_game(t_game *vars)
{
	ft_putstr("Moves: ");
	ft_putnbr(vars->qtt_moves);
	ft_putstr("\n");
	mlx_destroy_image(vars->mlx, vars->batman);
	mlx_destroy_image(vars->mlx, vars->b_b);
	mlx_destroy_image(vars->mlx, vars->batarang);
	mlx_destroy_image(vars->mlx, vars->mobile);
	mlx_destroy_image(vars->mlx, vars->grass);
	mlx_destroy_image(vars->mlx, vars->rocks);
	mlx_destroy_window(vars->mlx, vars->mlx_w);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_matrix(vars->map);
	exit(0);
}
