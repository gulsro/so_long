/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 12:18:59 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 17:52:36 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_down(t_map *my_map)
{
	if (check_character(my_map, my_map->x_p_location,
			my_map->y_p_location + 1, '1') == 0)
	{
		my_map->move++;
		my_map->y_p_location++;
		my_map->graphs->bag_img->instances[0].y += 64;
		ft_printf("%d\n", my_map->move);
		move_check(my_map);
	}
}

void	move_up(t_map *my_map)
{
	if (check_character(my_map, my_map->x_p_location,
			my_map->y_p_location - 1, '1') == 0)
	{
		my_map->move++;
		my_map->y_p_location--;
		my_map->graphs->bag_img->instances[0].y -= 64;
		ft_printf("%d\n", my_map->move);
		move_check(my_map);
	}
}

void	move_left(t_map *my_map)
{
	if (check_character(my_map, my_map->x_p_location - 1,
			my_map->y_p_location, '1') == 0)
	{
		my_map->move++;
		my_map->x_p_location--;
		my_map->graphs->bag_img->instances[0].x -= 64;
		ft_printf("%d\n", my_map->move);
		move_check(my_map);
	}
}

void	move_right(t_map *my_map)
{
	if (check_character(my_map, my_map->x_p_location + 1,
			my_map->y_p_location, '1') == 0)
	{
		my_map->move++;
		my_map->x_p_location++;
		my_map->graphs->bag_img->instances[0].x += 64;
		ft_printf("%d\n", my_map->move);
		move_check(my_map);
	}
}

void	move_check(t_map *my_map)
{
	if (check_character(my_map, my_map->x_p_location,
			my_map->y_p_location, 'C'))
	{
		catch_collectable(my_map);
	}
	else if (my_map->collected != my_map->count_c
		&& check_character(my_map, my_map->x_p_location,
			my_map->y_p_location, 'E'))
	{
		ft_printf("Not yet!\n Clean all the mess.\n");
	}
	else if (my_map->collected == my_map->count_c
		&& check_character(my_map, my_map->x_p_location,
			my_map->y_p_location, 'E'))
	{
		my_map->exit_open = 1;
		game_over(my_map);
	}
}
