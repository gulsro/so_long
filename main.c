#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*my_map;
	int		fd;
	char	**map_arr;

	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	my_map->height_y = 0;
	fd = open_file(argv);
	map_arr = make_map_arr(my_map, fd);
	
	map_scale(my_map);
	printf("height: %d \n", my_map->height_y);
	printf("width: %d \n", my_map->width_x);
	
	//wall valid
	printf("walls are good: %d\n", check_side_walls(my_map));
	

/*	for(int i = 0; i < 18; i++)
	{
		printf("map elements: %c\n", map_arr[1][i]);
		
	}
*/

}
