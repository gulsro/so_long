#include "lib/MLX42/include/MLX42/MLX42.h"
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
	return (0);

	mlx_loop(mlx);
//	mlx_close_window(mlx);
}
