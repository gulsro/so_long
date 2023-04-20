#include "so_long.h"

static mlx_texture_t	*protect1(mlx_texture_t *elem)
{
	if (!elem)
		return (NULL);
	return (elem);
}

void	make_image(mlx_t *mlx, t_graphs *graphs)
{
	/*t_graphs	*graphs;

	graphs = malloc(sizeof(t_graphs));
	if (!graphs)
		ft_exit("Graphs malloc failed", 1);*/
	graphs->bin_text = protect1(mlx_load_png("./images/bin.png"));
	graphs->poop_text = protect1(mlx_load_png("./images/dog_poop.png"));
	graphs->grass_text = protect1(mlx_load_png("./images/grass.png"));
	graphs->bag_text = protect1(mlx_load_png("./images/plastic_bag.png"));
	graphs->wall_text = protect1(mlx_load_png("./images/wall.png"));
	//we have textures, now convert them to images
	graphs->bin_img = mlx_texture_to_image(mlx, graphs->bin_text);
	graphs-> poop_img = mlx_texture_to_image(mlx, graphs->poop_text);
	graphs->grass_img = mlx_texture_to_image(mlx, graphs->grass_text);
	graphs->bag_img = mlx_texture_to_image(mlx, graphs->bag_text);
	graphs->wall_img = mlx_texture_to_image(mlx, graphs->wall_text);
}

void	image_to_window(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	display_grass(mlx, graphs, my_map);
	display_wall(mlx, graphs, my_map);
	display_bin(mlx, graphs, my_map);
	display_poop(mlx, graphs, my_map);
	display_bag(mlx, graphs, my_map);
}
