/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:42:21 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 18:33:02 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static mlx_t	*window_init(t_map *my_map)
{
	my_map->mlx = mlx_init(64 * my_map->width_x,
			64 * my_map->height_y, "DoggySheet", false);
	if (!my_map->mlx)
		ft_exit("MLX cant be created");
	return (my_map->mlx);
}

int	main(int argc, char **argv)
{
	t_map	*my_map;

	if (argc != 2)
		ft_exit("argc");
	my_map = malloc(sizeof(t_map));
	if (!my_map)
		ft_exit("Error\nMalloc failed");
	my_map->graphs = malloc(sizeof(t_graphs));
	if (!my_map->graphs)
		ft_exit("Error\nMalloc failed");
	init_map_struct(my_map);
	if (check_map(my_map, argv) == 0)
	{
		my_map->mlx = window_init(my_map);
		background_to_window(my_map);
		images_to_window(my_map);
		mlx_key_hook(my_map->mlx, mlx_key_hook_callback, (void *)my_map);
		mlx_loop(my_map->mlx);
		mlx_terminate(my_map->mlx);
		free_map_arr(my_map->map_arr);
		free(my_map->graphs);
		free(my_map);
	}
	return (0);
}
