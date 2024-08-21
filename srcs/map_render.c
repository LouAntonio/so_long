/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:19:07 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/21 12:35:57 by lantonio         ###   ########.fr       */
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

void	keep_rendering(t_game game, t_point pos, int i, int j)
{
	pos.x = 50 * j;
	pos.y = 50 * i;
	if (game.map[i][j] == '1')
		game.img = game.rocks;
	else if (game.map[i][j] == '0')
		game.img = game.grass;
	else if (game.map[i][j] == 'C')
		game.img = game.batarang;
	else if (game.map[i][j] == 'P')
		game.img = game.player;
	else if (game.map[i][j] == 'E')
		game.img = game.mobile;
	mlx_put_image_to_window(game.mlx, game.mlx_w, game.img, pos.x, pos.y);
}

void	map_render(t_game game)
{
	int		i;
	int		j;
	int		k;
	int		l;
	t_point	pos;

	k = -1;
	i = -1;
	while (game.map[++i])
	{
		j = -1;
		while (game.map[i][++j])
			keep_rendering(game, pos, i, j);
	}
}

void	game_init(char **map)
{
	t_game	game;
	int		x;
	int		y;

	game.win_h = matrix_len(map) * 50;
	game.win_w = ft_strlen(map[0]) * 50;
	game.mlx = mlx_init();
	game.mlx_w = mlx_new_window(game.mlx, game.win_w, game.win_h, "so_long");
	game.batman = mlx_xpm_file_to_image(game.mlx, "./textures/P.xpm", &x, &y);
	game.bat_left = mlx_xpm_file_to_image(game.mlx,
			"./textures/Pl.xpm", &x, &y);
	game.batarang = mlx_xpm_file_to_image(game.mlx, "./textures/C.xpm", &x, &y);
	game.mobile = mlx_xpm_file_to_image(game.mlx, "./textures/E.xpm", &x, &y);
	game.grass = mlx_xpm_file_to_image(game.mlx, "./textures/0.xpm", &x, &y);
	game.rocks = mlx_xpm_file_to_image(game.mlx, "./textures/1.xpm", &x, &y);
	game.player = game.batman;
	game.map = map;
	game.qtt_moves = 0;
	map_render(game);
	mlx_hook(game.mlx_w, 2, 1L << 0, key_press_handler, &game);
	mlx_hook(game.mlx_w, 17, 1L << 0, close_game, &game);
	mlx_loop(game.mlx);
}
