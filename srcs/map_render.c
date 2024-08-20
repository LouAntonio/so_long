/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:19:07 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/20 12:37:26 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putchar_on_map(char c)
{
	int	i;

	if (c == '0')
		c = '.';
	i = write(1, &c, 1);
}

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			ft_putchar_on_map(map[i][j]);
		ft_putchar_on_map('\n');
	}
	ft_putchar_on_map('\n');
}

void	keep_rendering(t_game vars, t_point pos, int i, int j)
{
	pos.x = 50 * j;
	pos.y = 50 * i;
	if (vars.map[i][j] == '1')
		vars.img = vars.rocks;
	else if (vars.map[i][j] == '0')
		vars.img = vars.grass;
	else if (vars.map[i][j] == 'C')
		vars.img = vars.batarang;
	else if (vars.map[i][j] == 'P')
		vars.img = vars.player;
	else if (vars.map[i][j] == 'E')
		vars.img = vars.mobile;
	mlx_put_image_to_window(vars.mlx, vars.mlx_w, vars.img, pos.x, pos.y);
}

void	map_render(t_game vars)
{
	int		i;
	int		j;
	int		k;
	int		l;
	t_point	pos;

	k = -1;
	i = -1;
	while (vars.map[++i])
	{
		j = -1;
		while (vars.map[i][++j])
			keep_rendering(vars, pos, i, j);
	}
}

void	game_init(char **map)
{
	t_game	vars;
	int		x;
	int		y;

	vars.win_h = matrix_len(map) * 50;
	vars.win_w = ft_strlen(map[0]) * 50;
	vars.mlx = mlx_init();
	vars.mlx_w = mlx_new_window(vars.mlx, vars.win_w, vars.win_h, "so_long");
	vars.batman = mlx_xpm_file_to_image(vars.mlx, "./textures/P.xpm", &x, &y);
	vars.b_b = mlx_xpm_file_to_image(vars.mlx, "./textures/Pl.xpm", &x, &y);
	vars.batarang = mlx_xpm_file_to_image(vars.mlx, "./textures/C.xpm", &x, &y);
	vars.mobile = mlx_xpm_file_to_image(vars.mlx, "./textures/E.xpm", &x, &y);
	vars.grass = mlx_xpm_file_to_image(vars.mlx, "./textures/0.xpm", &x, &y);
	vars.rocks = mlx_xpm_file_to_image(vars.mlx, "./textures/1.xpm", &x, &y);
	vars.player = vars.batman;
	vars.map = map;
	vars.map_cpy = map;
	vars.qtt_moves = 0;
	map_render(vars);
	mlx_hook(vars.mlx_w, 2, 1L << 0, key_press_handler, &vars);
	mlx_hook(vars.mlx_w, 17, 1L << 0, close_game, &vars);
	mlx_loop(vars.mlx);
}
