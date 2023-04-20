#include "so_long.h"

static int	protect1(t_graps* elem)
{	
	if (!elem)
		return (NULL);
}

void	load_image(mlx_t *mlx)
{
	mlx_texture_t	*t_graphs;

	t_graphs->bin_text = protect1(mlx_load_png("./images/bin.png"));
	t_graphs->poop_text = protect1(mlx_load_png("./images/dog_poop.png"));
	t_graphs->grass_text = protect1(mlx_load_png("./images/grass.png"));
	t_graphs->bag_text = protect1(mlx_load_png("./images/plastic_bag.png"));
	t_graphs->wall_text = protect1(mlx_load_png("./images/wall.png"));

}
