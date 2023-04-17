#include "so_long.h"

int	map_height(int fd)
{
	char	*line;
	int		i;
		
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		if (!line)
			break ;
		free(line);
	}
	free(line);
//	printf("line numbers: %d\n", i);
	return (i);
}
/*
static	int	check_map_char(char c)
{
	return (c == '1' || c == 'P' || c == '0' || c == 'C' || c == 'E');
}*/
/*
int check_outside_walls_valid(char **map_arr)
{
	int	x;
	int	y;

	x = 0;
	while (map_arr[x][y])
	{
		y = x;
		while (map_arr[x][y])
		{
			if (map_arr[x][y] != 1)
				return (0);
			x++;
		}
	}
}	
*/
