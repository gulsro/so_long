#include "so_long.h"

void	free_map_arr(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		free(map_arr[i]);
		i++;	
	}
	free(map_arr);
}
