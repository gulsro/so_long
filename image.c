#include "so_long.h"

static mlx_texture_t	*protect1(mlx_texture_t *elem)
{
	if (!elem)
		return (NULL);
	return (elem);
}

static void	make_image(mlx_t *mlx, t_graphs *graphs)
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

void	images_to_window(t_map *my_map)
{
	int	x;
	int	y;

	make_image(my_map->mlx, my_map->graphs);
	y = 0;
	while (my_map->map_arr[y])
	{
		x = 0;
		while (my_map->map_arr[y][x])
		{
			mlx_image_to_window(my_map->mlx, my_map->graphs->grass_img, x * 64, y * 64);
			if (my_map->map_arr[y][x] == '1')
				mlx_image_to_window(my_map->mlx, my_map->graphs->wall_img, x * 64, y * 64);
			if (my_map->map_arr[y][x] == 'E')
				mlx_image_to_window(my_map->mlx, my_map->graphs->bin_img, x * 64, y * 64);
			 if (my_map->map_arr[y][x] == 'C')
				mlx_image_to_window(my_map->mlx, my_map->graphs->poop_img, x * 64, y * 64);
			if (my_map->map_arr[y][x] == 'P')
                                mlx_image_to_window(my_map->mlx, my_map->graphs->bag_img, x * 64, y * 64);
			 x++;
		}
		y++;
	}
}
