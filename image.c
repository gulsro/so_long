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
	graphs->bin_text = protect1(mlx_load_png("../in_pro/bin.png"));
	graphs->poop_text = protect1(mlx_load_png("../in_pro/dog_poop.png"));
	graphs->grass_text = protect1(mlx_load_png("../in_pro/grass.png"));
	graphs->bag_text = protect1(mlx_load_png("../in_pro/plastic_bag.png"));
	graphs->wall_text = protect1(mlx_load_png("../in_pro/wall.png"));
	//we have textures, now convert them to images
	graphs->bin_img = mlx_texture_to_image(mlx, graphs->bin_text);
	graphs-> poop_img = mlx_texture_to_image(mlx, graphs->poop_text);
	graphs->grass_img = mlx_texture_to_image(mlx, graphs->grass_text);
	graphs->bag_img = mlx_texture_to_image(mlx, graphs->bag_text);
	graphs->wall_img = mlx_texture_to_image(mlx, graphs->wall_text);
}

void	place_sprites(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (my_map->map_arr[i])
	{
		j = 0;
		while (my_map->map_arr[i][j])
		{
			mlx_image_to_window(mlx, graphs->grass_img, j * 64, i * 64);
			if (my_map->map_arr[i][j] == '1')
				mlx_image_to_window(mlx, graphs->wall_img, j * 64, i * 64);
			else if (my_map->map_arr[i][j] == 'P')
				mlx_image_to_window(mlx, graphs->bag_img, j * 64, i * 64);
			else if (my_map->map_arr[i][j] == 'E')
				mlx_image_to_window(mlx, graphs->bin_img, j * 64, i * 64);
			else if (my_map->map_arr[i][j] == 'C')
				mlx_image_to_window(mlx, graphs->poop_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}
