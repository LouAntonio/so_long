#include "../includes/so_long.h"

int main()
{
	void	*mlx = mlx_init();
	void	*window = mlx_new_window(mlx, 500, 500, "teste");
	int	a = 200, b = 200;
	void	*img = mlx_xpm_file_to_image(mlx, "./img/file.xpm", &a, &b);
	mlx_put_image_to_window(mlx, window, img, 0, 0);
	mlx_loop(mlx);
}
