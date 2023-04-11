#include "lib/MLX42/include/MLX42/MLX42.h"
#define WIDTH 800
#define HEIGHT 400

int main()
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "DoggySheet", false);
	if (!mlx)
		return (0);
	return (0);

}
