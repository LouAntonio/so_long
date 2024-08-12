/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:19:07 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/12 16:52:01 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_render(char **map)
{
	int	window_width;
	int	window_height;
	void	*mlx;
	void	*mlx_w;
	void	*img;
	int 	w = 200;
	int 	h = 200;
	int 	x;
	int 	y;

	window_height = matrix_len(map) * 50;
	window_width = ft_strlen(map[0]) * 50;
	mlx = mlx_init();
	mlx_w = mlx_new_window(mlx, window_width, window_height, "so_long");

	void *batarang = mlx_xpm_file_to_image(mlx, "./textures/batarang.xpm", &w, &h);
	void *batman = mlx_xpm_file_to_image(mlx, "./textures/batman.xpm", &w, &h);
	void *batmobile = mlx_xpm_file_to_image(mlx, "./textures/batmobile.xpm", &w, &h);
	void *grass = mlx_xpm_file_to_image(mlx, "./textures/grass.xpm", &w, &h);
	void *rocks = mlx_xpm_file_to_image(mlx, "./textures/rocks.xpm", &w, &h);
	
	int i = 0;
	int j;
	while (map[i]){
		j = 0;
		while (map[i][j]){
			x = 50 * j;
			y = 50 * i;
			if (map[i][j] == '1')
				img = rocks;
			else if (map[i][j] == '0')
				img = grass;
			else if (map[i][j] == 'C')
				img = batarang;
			else if (map[i][j] == 'P')
				img = batman;
			else if (map[i][j] == 'E')
				img = batmobile;
			mlx_put_image_to_window(mlx, mlx_w, img, x, y);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
