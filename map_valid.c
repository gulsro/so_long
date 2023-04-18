#include "so_long.h"

void	map_scale(t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (my_map->map_arr[i] != '\0')
	{
		i++;
	}
	my_map->height_y = i;
	while (my_map->map_arr[0][j] != '\0')
	{
		j++;
	}
	my_map->width_x = j;
}
/*
static	int	check_map_char(char c)
{
	return (c == '1' || c == 'P' || c == '0' || c == 'C' || c == 'E');
}*/

int check_side_walls(t_map	*my_map)
{
	int	x;
	int	y;

	y = 0;
	while (my_map->map_arr[y] != '\0')
	{
		if (my_map->map_arr[y][0] != '1' 
				|| my_map->map_arr[y][my_map->width_x - 1] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (my_map->map_arr[0][x] != '\0' 
			&& my_map->map_arr[my_map->height_y - 1][x] != '\0')
	{
		if (my_map->map_arr[0][x] != '1' 
				|| my_map->map_arr[my_map->height_y - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}	

