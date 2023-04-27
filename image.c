#include "so_long.h"

static mlx_texture_t	*protect1(mlx_texture_t *elem)
{
	if (!elem)
		return (NULL);
	return (elem);
}

static void	make_texture(t_map *my_map)
{
	my_map->graphs->bin_text = protect1(mlx_load_png("./images/bin.png"));
	my_map->graphs->poop_text = protect1(mlx_load_png("./images/dog_poop.png"));
	my_map->graphs->grass_text = protect1(mlx_load_png("./images/grass.png"));
	my_map->graphs->bag_text = protect1(mlx_load_png("./images/plastic_bag.png"));
	my_map->graphs->wall_text = protect1(mlx_load_png("./images/wall.png"));
	my_map->graphs->doggy_text = protect1(mlx_load_png("./images/doggy.png"));
	my_map->graphs->gameover_text = protect1(mlx_load_png("./images/gameover.png"));
}

static void	make_image(t_map *my_map)
{
	make_texture(my_map);
	my_map->graphs->bin_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->bin_text);
	my_map->graphs-> poop_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->poop_text);
	my_map->graphs->grass_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->grass_text);
	my_map->graphs->bag_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->bag_text);
	my_map->graphs->wall_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->wall_text);
	my_map->graphs->doggy_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->doggy_text);
	my_map->graphs->gameover_img = mlx_texture_to_image(my_map->mlx, my_map->graphs->gameover_text);
	mlx_delete_texture(my_map->graphs->wall_text);
	mlx_delete_texture(my_map->graphs->grass_text);
	mlx_delete_texture(my_map->graphs->bin_text);
	mlx_delete_texture(my_map->graphs->bag_text);
	mlx_delete_texture(my_map->graphs->poop_text);
	mlx_delete_texture(my_map->graphs->gameover_text);
	mlx_delete_texture(my_map->graphs->doggy_text);
}

static void	background_to_window(t_map *my_map)
{
	int     x;
	int     y;

	make_image(my_map);
	y = 0;
	while (my_map->map_arr[y])
	{
		x = 0;
		while (my_map->map_arr[y][x])
		{
			mlx_image_to_window(my_map->mlx, my_map->graphs->grass_img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	images_to_window(t_map *my_map)
{
	int	x;
	int	y;

	make_image(my_map);
	background_to_window(my_map);
	y = 0;
	while (my_map->map_arr[y])
	{
		x = 0;
		while (my_map->map_arr[y][x])
		{
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
