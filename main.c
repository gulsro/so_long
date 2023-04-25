#include "so_long.h"

static mlx_t   *window_init(t_map *my_map)
{
  //  mlx_set_setting(MLX_MAXIMIZED, true);
    my_map->mlx = mlx_init(64 * my_map->width_x, 64 * my_map->height_y, "DoggySheet", false);
    if (!my_map->mlx)
            ft_exit("MLX cant be created", 1);
    return (my_map->mlx);
}

int main(int argc, char **argv)
{
	t_map	*my_map;

	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	my_map->graphs = malloc(sizeof(t_graphs));
	if (!my_map || !my_map->graphs)
		ft_exit("Error\nMalloc failed", 1);
	init_map_struct(my_map);
	if (check_map(my_map, argv) == 0)
	{
		my_map->mlx = window_init(my_map);
		
		images_to_window(my_map);
		mlx_key_hook(my_map->mlx, mlx_key_hook_callback, (void*)my_map);
		mlx_loop(my_map->mlx);
    		mlx_terminate(my_map->mlx);
		int i = 0;
		while (my_map->map_arr[i])
		{
			printf("map elements: %s\n", my_map->map_arr[i]);
			i++;
		}
		printf("collectable = %d\n", my_map->count_c);
		printf("player location  = (%d, %d)\n", my_map->x_p_location, my_map->y_p_location);
//		printf("instance player location  = (%d, %d)\n", my_map->graphs->bag_img->instances[0].x, my_map->graphs->bag_img->instances[0].y);
	}
	printf("collected = %d\n", my_map->collected);
	printf("count_c = %d\n", my_map->count_c);
//	system("leaks so_long");
	return 0;
}
