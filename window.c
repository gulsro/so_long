#include "so_long.h"

mlx_t	*window_init(void)
{
	mlx_t   *mlx;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "DoggySheet", false);
	if (!mlx)
            ft_exit("MLX cant be created", 1);
	return (mlx);
}

void	display_image(mlx_t *mlx)
{
	mlx_image_t *img;
	uint32_t	i;
    uint32_t	j;
	
	i = 0;
	j = 0;
	img = mlx_new_image(mlx, 64, 64);
    if (!img)
        ft_exit("IMG struct cant be created", 1);
	while (i < 64)
	{
		j = 0;
		while (j < 64)
		{
			mlx_put_pixel(img, i, j, 0xF70AF0B3);
			j++;
		}
		i++;
	}
	if (mlx_image_to_window(mlx, img, (mlx->width)/2-(img->width)/2, (mlx->height)/2-(img->height)/2) < 0)
		ft_exit("XXX", 1);
}
