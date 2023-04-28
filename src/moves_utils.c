/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:21:54 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 12:46:10 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	catch_collectable(t_map *my_map)
{
	int	i;

	i = 0;
	while (i < my_map->count_c)
	{
		if (my_map->graphs->poop_img->instances[i].x
			== my_map->x_p_location * 64
			&& my_map->graphs->poop_img->instances[i].y
			== my_map->y_p_location * 64)
		{
		my_map->graphs->poop_img->instances[i].enabled = 0;
		my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		my_map->collected++;
		}
		i++;
	}
}

int	check_character(t_map *my_map, int x, int y, char character)
{
	if (my_map->map_arr[y][x] == character)
		return (1);
	return (0);
}

void	game_over(t_map *my_map)
{
	my_map->graphs->bag_img->instances[0].enabled = 0;
	mlx_image_to_window(my_map->mlx, my_map->graphs->gameover_img,
		(my_map->width_x / 2) * 64, 64);
	ft_printf("Game over!\n");
}
