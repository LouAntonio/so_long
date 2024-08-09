/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 16:33:57 by lantonio          #+#    #+#             */
/*   Updated: 2024/08/09 13:29:53 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "includes/so_long.h"

// typedef struct s_vars{
// 	void	*mlx;
// 	void	*mlx_w;
// }	t_vars;

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int 	close(int keycode, t_vars *vars)
// {
// 	if (keycode == 65307)
// 		mlx_destroy_window(vars->mlx, vars->mlx_w);
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_w;
// 	void	*img;
// 	int 	a = 640;
// 	int 	b = 426;

// 	mlx = mlx_init();
// 	mlx_w = mlx_new_window(mlx, 800, 800, "LouAntonio");

// 	img = mlx_xpm_file_to_image(mlx, "./file.xpm", &a, &b);
// 	mlx_put_image_to_window(mlx, mlx_w, img, ((800 - a) / 2), ((800 - b) / 2));

// 	mlx_loop(mlx);
// }

int main(int ac, char **av)
{
	int i = 0;
	char **map = get_map(av);

	if (map_validator(map))
		printf("OK\n");
	else
		printf("KO\n");
	
	return (0);
}
