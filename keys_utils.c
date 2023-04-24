#include "so_long.h"

void	catch_collectable(t_map *my_map, int x, int y)
{
	int	i;

	i = 0;
	
	while (i < my_map->count_c)
	{
		if (my_map->graphs->poop_img->instances[i].x == x * 64
			&& my_map->graphs->poop_img->instances[i].y == y * 64)
		{
			my_map->graphs->poop_img->instances[i].enabled = 0;
			my_map->count_c--;
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
