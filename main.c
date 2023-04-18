#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*my_map;
	int		fd;
	char	**map_arr;

	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	fd = open_file(argv);
	map_arr = make_map_arr(my_map, fd);
	
	map_scale(my_map);
	printf("height: %d \n", my_map->height_y);
	printf("width: %d \n", my_map->width_x);
	
	//wall valid
	printf("rect, walls and chars are all good: %d\n", check_all(my_map));
	/*	printf("walls surround: %d\n", check_side_walls(my_map));
	printf("walls are rectangular: %d\n", check_rectangular_map(my_map));	
	printf("chars in map are okay: %d\n", check_number_of_ecp(my_map));
*/
	char **cpy_arr;
	cpy_arr = create_map_arr_cpy(my_map);
	for(int i = 0; i < 5; i++)
	{
		printf("map elements: %s\n", cpy_arr[i]);
	}


}
