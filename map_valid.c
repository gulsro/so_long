#include "so_long.h"

int check_walls(t_map	*my_map)
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

int	check_rectangular_map(t_map *my_map)
{
	return ((my_map->width_x > my_map->height_y) 
			|| (my_map->width_x < my_map->height_y));
}

static int check_char(char c)
{
    return (c == '1' || c == 'P' || c == '0' || c == 'C' || c == 'E');
}

int	check_number_of_ecp(t_map *my_map)
{
	int	i;
	int	j;
	int	e;
	int	c;
	int	p;

	e = 0;
	c = 0;
	p = 0;
	i = 0;
	while (my_map->map_arr[i] != '\0')
	{
		j = 0;
		while (my_map->map_arr[i][j] != '\0')
		{
			if (check_char(my_map->map_arr[i][j]) != 1)
				return (0);
			if (my_map->map_arr[i][j] == 'E')
				e++;
			if (my_map->map_arr[i][j] == 'C')
                c++;
			if (my_map->map_arr[i][j] == 'P')
                p++;
			j++;
		}
		i++;
	}
	if (e > 0 && c > 0 && p > 0)
		return (1);
	return (0);
}

int	check_all(t_map *my_map)
{
	return (check_number_of_ecp(my_map) && check_rectangular_map(my_map) 
			&& check_walls(my_map));
}
