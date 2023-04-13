#include "lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#define WIDTH 800
#define HEIGHT 400

static void	ft_error(void)
{
	perror("error");
	exit(1);
}

int main()
{
	mlx_t	*mlx;
	
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "DoggySheet", false);
	if (!mlx)
		ft_error();
	//create and display the image
	mlx_image_t *img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);

	mlx_loop(mlx);
//	mlx_close_window(mlx);
}
