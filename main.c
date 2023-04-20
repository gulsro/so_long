#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*my_map;
	mlx_t   *mlx;

	mlx = NULL;
	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	if (!my_map)
		ft_exit("My_map malloc failed", 1);
	init_map_struct(my_map);
	if (check_map(my_map, argv) == 0)
	{
		mlx = window_init();
		display_image(mlx);
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
