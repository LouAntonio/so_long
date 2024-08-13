/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:19:07 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/13 18:45:34 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_render(t_game vars)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (vars.map[i]){
		j = 0;
		while (vars.map[i][j]){
			x = 50 * j;
			y = 50 * i;
			if (vars.map[i][j] == '1')
				vars.img = vars.rocks;
			else if (vars.map[i][j] == '0')
				vars.img = vars.grass;
			else if (vars.map[i][j] == 'C')
				vars.img = vars.batarang;
			else if (vars.map[i][j] == 'P')
				vars.img = vars.player;
			else if (vars.map[i][j] == 'E')
				vars.img = vars.batmobile;
			mlx_put_image_to_window(vars.mlx, vars.mlx_w, vars.img, x, y);
			j++;
		}
		i++;
	}
}

void	game_init(char **map)
{
	t_game	vars;
	int 	x;
	int 	y;

	vars.window_height = matrix_len(map) * 50;
	vars.window_width = ft_strlen(map[0]) * 50;
	vars.mlx = mlx_init();
	vars.mlx_w = mlx_new_window(vars.mlx, vars.window_width, vars.window_height, "so_long");

	vars.player = mlx_xpm_file_to_image(vars.mlx, "./textures/batman.xpm", &x, &y);
	vars.batman = mlx_xpm_file_to_image(vars.mlx, "./textures/batman.xpm", &x, &y);
	vars.batman_left = mlx_xpm_file_to_image(vars.mlx, "./textures/batman_left.xpm", &x, &y);
	vars.batarang = mlx_xpm_file_to_image(vars.mlx, "./textures/batarang.xpm", &x, &y);
	vars.batmobile = mlx_xpm_file_to_image(vars.mlx, "./textures/batmobile.xpm", &x, &y);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, "./textures/grass.xpm", &x, &y);
	vars.rocks = mlx_xpm_file_to_image(vars.mlx, "./textures/rocks.xpm", &x, &y);
	vars.map = map;

	map_render(vars);
	mlx_hook(vars.mlx_w, 2, 1L<<0, key_press_handler, &vars);
	mlx_loop(vars.mlx);
}
