#include "so_long.h"

int main(int argc, char **argv)
{
	t_map	*my_map;

	if (argc != 2)
		ft_exit("argc", 1);
	my_map = malloc(sizeof(t_map));
	if (!my_map)
		ft_exit("My_map malloc failed", 1);
/*	init_map_struct(my_map);
	if (check_map(my_map, argv) == 0)
	{
		int i = 0;
		while (my_map->cpy_arr[i])
		{
                	printf("map elements: %s\n", my_map->cpy_arr[i]);
                	i++;
        	}
	}*/
	int	fd = open_file(argv[1]);
	make_map_arr(my_map, fd);
	
	map_scale(my_map);
	printf("height: %d \n", my_map->height_y);
	printf("width: %d \n", my_map->width_x);
	
	//wall valid
	printf("rect, walls and chars are all good: %d\n", check_all(my_map));

	//check if map_arr can be doubled
	char **cpy;
	cpy = create_map_arr_cpy(my_map);
	int i = 0;
	while (cpy[i])
	{
		printf("map elements: %s\n", cpy[i]);
		i++;
	}
	printf("----------------------\n");
	int j = 0;
    while (my_map->map_arr[j])
    {
        printf("map elements: %s\n", my_map->map_arr[j]);
        j++;
    }


	//print player location
	find_player(my_map);
	printf("location of the player is: %d, %d\n", my_map->x_p_location, my_map->y_p_location);


	//after calling algo
	printf("\n\nafter calling ALGO\n");
	char **last_map;
	last_map = move(my_map, cpy, my_map->x_p_location, my_map->y_p_location);

	int m = 0;
        while (my_map->map_arr[m])
        {
                printf("map elements: %s\n", my_map->map_arr[m]);
                m++;
        }
        printf("----------------------\n");
        int n = 0;
    while (last_map[n])
    {
        printf("map elements: %s\n", last_map[n]);
        n++;
    }
//    printf("After move() chars in cpy_arr are valid: %d\n", check_valid_chars_after_move(last_map));

}
