#include "so_long.h"

void	free_map_arr(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		free(map_arr[i]);
		i++;	
	}
	free(map_arr);
}

void	free_textures(t_map *my_map)
{
	mlx_delete_texture(my_map->graphs->wall_text);
	mlx_delete_texture(my_map->graphs->grass_text);
	mlx_delete_texture(my_map->graphs->bin_text);
	mlx_delete_texture(my_map->graphs->bag_text);
	mlx_delete_texture(my_map->graphs->poop_text);
	mlx_delete_texture(my_map->graphs->gameover_text);
	mlx_delete_texture(my_map->graphs->doggy_text);
}
