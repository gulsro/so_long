#include  "so_long.h"

int	is_walkable(t_map *my_map, int new_x, int new_y)
{
	//char	**cpy_arr;

	create_map_arr_cpy(my_map);
	if (my_map->cpy_arr[new_y][new_x] == 'E' || my_map->cpy_arr[new_y][new_x] == 'C' || my_map->cpy_arr[new_y][new_x] == '0' || my_map->cpy_arr[new_y][new_x] == 'P')
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
	while (my_map->map_arr[i] != '\0')
	{
		j = 0;
		while (my_map->map_arr[i][j] != '\0')
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
//	my_map->y_p_location = i;
//	my_map->x_p_location = j;
}
/*
void	move(t_map *my_map, int new_x, int new_y)
{
	find_player(my_map);
	if (is_walkable(my_map, my_path->x_p_location, my_path->y_p_location) != 0)
		my_path->y_p_location = '1';
}*/
