#include "so_long.h"

int main(int argc, char **argv)
{
	int		fd;
	char	**map_arr;

	if (argc != 2)
		ft_exit("argc", 1);
	fd = open_file(argv);
	map_arr = make_map_arr(fd);
	for(int i = 0; i < 7; i++)
	{
		printf("map elements: %s\n", map_arr[i]);
	}


}
