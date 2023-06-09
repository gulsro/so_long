/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:41:07 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 18:25:53 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_map_struct(t_map *my_map)
{
	my_map->map_arr = NULL;
	my_map->cpy_arr = NULL;
	my_map->count_c = 0;
	my_map->count_p = 0;
	my_map->count_e = 0;
	my_map->width_x = 0;
	my_map->height_y = 0;
	my_map->x_p_location = 0;
	my_map->y_p_location = 0;
	my_map->move = 0;
	my_map->collected = 0;
	my_map->exit_open = 0;
}

int	check_map(t_map *my_map, char **argv)
{
	int		fd;
	char	**cpy;
	char	**altered_cpy;

	fd = open_file(argv[1]);
	make_map_arr(my_map, fd);
	map_scale(my_map);
	if (check_all(my_map) != 1)
	{
		free_map_arr(my_map->map_arr);
		return (1);
	}
	find_player(my_map);
	cpy = create_map_arr_cpy(my_map);
	altered_cpy = move(my_map, cpy, my_map->x_p_location, my_map->y_p_location);
	if (check_valid_chars_after_move(altered_cpy) != 1)
	{
		free_map_arr(cpy);
		ft_exit("Error\nPath is invalid");
	}
	free_map_arr(cpy);
	cpy = NULL;
	return (0);
}
