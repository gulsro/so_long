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

/*int check_side_walls(t_map	*my_map)
{
	int	x;
	int	y;

	x = 0;
	while (my_map->map_arr[y])
	{
		if (my_map->map_arr[y][0] != '1' || my_map->map_arr[y][]
	}
}	
*/
