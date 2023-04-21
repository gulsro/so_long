#include "so_long.h"

static mlx_t   *window_init(t_map *my_map)
{
    mlx_t   *mlx;

    mlx_set_setting(MLX_MAXIMIZED, true);
    mlx = mlx_init(64 * my_map->width_x, 64 * my_map->height_y, "DoggySheet", false);
    if (!mlx)
            ft_exit("MLX cant be created", 1);
    return (mlx);
}

int main(int argc, char **argv)
{
	t_map	*my_map;
	t_graphs    *graphs;
	mlx_t   *mlx;

	mlx = NULL;
	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	graphs = malloc(sizeof(t_graphs));
	if (!my_map || !graphs)
		ft_exit("Error\nMalloc failed", 1);
	init_map_struct(my_map);
	if (check_map(my_map, argv) == 0)
	{
		mlx = window_init(my_map);
		make_image(mlx, graphs);
		place_sprites(mlx, graphs, my_map);
		mlx_loop(mlx);
    mlx_terminate(mlx);
		int i = 0;
		while (my_map->cpy_arr[i])
		{
			printf("map elements: %s\n", my_map->cpy_arr[i]);
			i++;
		}
	}
	return 0;
}
