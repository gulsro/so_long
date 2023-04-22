#include "so_long.h"

static mlx_t   *window_init(t_map *my_map)
{
    mlx_set_setting(MLX_MAXIMIZED, true);
    my_map->mlx = mlx_init(64 * my_map->width_x, 64 * my_map->height_y, "DoggySheet", false);
    if (!my_map->mlx)
            ft_exit("MLX cant be created", 1);
    return (my_map->mlx);
}

int main(int argc, char **argv)
{
	t_map	*my_map;
	t_graphs    *graphs;

	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	graphs = malloc(sizeof(t_graphs));
	if (!my_map || !graphs)
		ft_exit("Error\nMalloc failed", 1);
	init_map_struct(my_map);
	if (check_map(my_map, argv) == 0)
	{
		my_map->mlx = window_init(my_map);
		make_image(my_map->mlx, graphs);
		place_sprites(my_map->mlx, graphs, my_map);
		mlx_key_hook(my_map->mlx, mlx_key_hook_callback, (void*)my_map);
		mlx_loop(my_map->mlx);
    mlx_terminate(my_map->mlx);
		int i = 0;
		while (my_map->cpy_arr[i])
		{
			printf("map elements: %s\n", my_map->cpy_arr[i]);
			i++;
		}
	}
//	system("leaks so_long");
	return 0;
}
