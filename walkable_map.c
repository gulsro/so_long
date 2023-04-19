#include  "so_long.h"

int	is_walkable(t_map *my_map, int x_pos, int y_pos)
{
//	create_map_arr_cpy(my_map);
	if (my_map->cpy_arr[y_pos][x_pos] == 'E' || my_map->cpy_arr[y_pos][x_pos] == 'C' || my_map->cpy_arr[y_pos][x_pos] == '0' || my_map->cpy_arr[y_pos][x_pos] == 'P')
		return (1);
	else
		return (0);
}

void	find_player(t_map *my_map)
{
	int	i;
	int	j;

	i = 0;
	my_map->x_p_location = 0;
	my_map->y_p_location = 0;
	while (my_map->map_arr[i])
	{
		j = 0;
		while (my_map->map_arr[i][j])
		{
			if (my_map->map_arr[i][j] == 'P')
			{
				my_map->y_p_location = i;
   				my_map->x_p_location = j;	
			}
			j++;
		}
		i++;
	}
}

char	**move(t_map *my_map, char **cpy_arr, int x_pos, int y_pos)
{
//	create_map_arr_cpy(my_map);
//	find_player(my_map);
	//we have old positions via find_player() so that i dont have any arguments to hold old pos. in function
	if (cpy_arr[y_pos][x_pos] != '1')
//	if (my_map->cpy_arr[my_map->y_p_location][my_map->x_p_location] != '1')
	{
		if (is_walkable(my_map, x_pos, y_pos) == 1)
			 cpy_arr[y_pos][x_pos] = 'X';
		else
			return (cpy_arr);
		move(my_map, cpy_arr, x_pos + 1, y_pos);
		move(my_map, cpy_arr, x_pos - 1, y_pos);
		move(my_map, cpy_arr, x_pos, y_pos + 1);
		move(my_map, cpy_arr, x_pos, y_pos - 1);
	}
	return (cpy_arr);
}


