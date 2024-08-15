/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 18:03:23 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/15 18:05:26 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_on_read(int fd)
{
	ft_putstr("Error\nInvalid map!\n");
	close(fd);
	exit(1);
}

void	close_game(t_game *vars)
{
	ft_putstr("CLOSED\n");
	mlx_destroy_window(vars->mlx, vars->mlx_w);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_matrix(vars->map);
	exit(0);
}

void	finish_game(t_game *vars)
{
	ft_putstr("FINISHED\n");
	mlx_destroy_window(vars->mlx, vars->mlx_w);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_matrix(vars->map);
	exit(0);
}
