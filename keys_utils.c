#include "so_long.h"

void    catch_collectable(t_map *my_map)
{
	if (my_map->collected < my_map->count_c)
		my_map->collected++;
}

int	check_character(t_map *my_map, int x, int y, char character)
{
	if (my_map->map_arr[y][x] == character)
		return (1);
	return (0);
}


