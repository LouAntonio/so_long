#include "mlx/mlx.h"
#include <stdio.h>

typedef struct s_vars{
	void	*mlx;
	void	*mlx_w;
}	t_vars;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int 	close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->mlx_w);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_w;
	void	*img;
	int 	a = 640;
	int 	b = 426;

	mlx = mlx_init();
	mlx_w = mlx_new_window(mlx, 800, 800, "LouAntonio");

	img = mlx_xpm_file_to_image(mlx, "./file.xpm", &a, &b);
	mlx_put_image_to_window(mlx, mlx_w, img, ((800 - a) / 2), ((800 - b) / 2));

	mlx_loop(mlx);
}