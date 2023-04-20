#include "so_long.h"

void	display_poop(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (my_map->map_arr[i])
	{
		j = 0;
		while (my_map->map_arr[i][j])	
		{
			if (my_map->map_arr[i][j] == 'C')
				mlx_image_to_window(mlx, graphs->poop_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void    display_bag(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (my_map->map_arr[i])
	{
		j = 0;
		while (my_map->map_arr[i][j])
		{
			if (my_map->map_arr[i][j] == 'P')
				mlx_image_to_window(mlx, graphs->bag_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	display_bin(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (my_map->map_arr[i])
	{
		j = 0;
		while (my_map->map_arr[i][j])
		{
			if (my_map->map_arr[i][j] == 'E')
				mlx_image_to_window(mlx, graphs->bin_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void    display_grass(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
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
			j++;
		}
		i++;
	}
}

void    display_wall(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	while (my_map->map_arr[i])
	{
		j = 0;
		while (my_map->map_arr[i][j])
		{
			if (my_map->map_arr[i][j] == '1')
				mlx_image_to_window(mlx, graphs->wall_img, j * 64, i * 64);
			j++;
		}
	i++;
	}
}
