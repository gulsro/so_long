#include  "so_long.h"

int	is_walkable(t_map *my_map, int new_x, int new_y)
{
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
/*
void	move(t_map *my_map, char **cpy_arr, int new_x, int new_y)
{
	create_map_arr_cpy(my_map);
	find_player(my_map);
	if (my_map->cpy_arr[new_x][new_y] != '1')
	{
		if (is_walkable(my_map, new_x, new_y) != 0)
			 cpy_arr[new_y][new_x]= '7';
		else
			
	}

}*/
