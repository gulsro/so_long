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
	int	x;
	int	y;

	y = 0;
	while (my_map->map_arr[y])
	{
		x = 0;
		while (my_map->map_arr[y][x])
		{
			if (my_map->map_arr[y][x] == 'P')
			{
				my_map->y_p_location = y;
   				my_map->x_p_location = x;	
			}
			x++;
		}
		y++;
	}
}

char	**move(t_map *my_map, char **cpy_arr, int x_pos, int y_pos)
{
	if (cpy_arr[y_pos][x_pos] != '1')
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

int	check_valid_chars_after_move(char **cpy_arr)
{
	int	i;
	int	j;

	i = 0;
	while (cpy_arr[i])
	{
		j = 0;
		while (cpy_arr[i][j])
		{
			if (cpy_arr[i][j] != '1' && cpy_arr[i][j] != 'X' 
					&& cpy_arr[i][j] != '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}



