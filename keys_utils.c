#include "so_long.h"

void    catch_collectable(t_map *my_map)
{/*
	if (my_map->collected < my_map->count_c)
	{
		my_map->collected++;
	}*/
	int	i;

	i = 0;
	while (i < my_map->count_c)
	{
		if (my_map->graphs->poop_img->instances[i].x == my_map->x_p_location * 64
				&& my_map->graphs->poop_img->instances[i].y == my_map->y_p_location * 64)
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


