#include "lib/MLX42/include/MLX42/MLX42.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WIDTH 800
#define HEIGHT 400
#define BPP sizeof(int32_t)

static void	ft_error(void)
{
	perror("error");
	exit(1);
}

static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int main()
{
	mlx_t	*mlx;
	
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "DoggySheet", false);
	if (!mlx)
		ft_error();
	
	//create a buffer for the image
	mlx_image_t *img = mlx_new_image(mlx, 64, 64);
	if (!img)
		ft_error();

	//drawing the image
//	mlx_put_pixel(img, 0, 0, )
//
	//filling all pixels in image
	memset(img->pixels, 255, img->width * img->height * BPP);

	if (mlx_image_to_window(mlx, img, 110, 10) < 0)
		ft_error();
	
	//window ll be opened and width and height will be printed on the command line
	mlx_loop_hook(mlx, ft_hook, mlx);
	//now we see the window
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (0);
}
