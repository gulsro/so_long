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

	//check if map_arr can be doubled
//	char **cpy_arr;
	 create_map_arr_cpy(my_map);
	int i = 0;
	while (my_map->cpy_arr[i])
	{
		printf("map elements: %s\n", my_map->cpy_arr[i]);
		i++;
	}
	printf("----------------------\n");
	int j = 0;
    while (my_map->map_arr[j])
    {
        printf("map elements: %s\n", my_map->map_arr[j]);
        j++;
    }
	//find player location
	find_player(my_map);
	printf("location of the player is: %d, %d\n", my_map->x_p_location, my_map->y_p_location);
	

}
