#include  "so_long.h"

int	is_walkable(t_map *my_map, int new_x, int new_y)
{
	char	**cpy_arr;

	cpy_arr = create_map_arr_cpy(my_map);
	if (cpy_arr[new_y][new_x] == 'E' || cpy_arr[new_y][new_x] == 'C' || cpy_arr[new_y][new_x] == '0' || cpy_arr[new_y][new_x] == 'P')
		return (1);
	else
		return (0);
}


