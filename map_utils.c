#include "so_long.h"

void    map_scale(t_map *my_map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (my_map->map_arr[i])
	{
		i++;
	}
	my_map->height_y = i;
	while (my_map->map_arr[0][j])
	{
		j++;
	}
	my_map->width_x = j;
}

char	**create_map_arr_cpy(t_map *my_map)
{
	int		i;

	i = 0;
	my_map->cpy_arr = ft_calloc(my_map->height_y + 1, sizeof(char *));
	if (!my_map->cpy_arr)
		ft_exit("Map array cant be copied", 1);
	while (my_map->map_arr[i])
	{
		my_map->cpy_arr[i] = ft_strdup(my_map->map_arr[i]);
		i++;
	}
	my_map->cpy_arr[i] = NULL;
	return (my_map->cpy_arr);
}
