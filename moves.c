#include "so_long.h"

void	move_down(t_map *my_map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < my_map->height_y)
	{
		x = -1;
		while (++x < my_map->width_x)
		{
			if (my_map->map_arr[y][x] == 'P')
			{
				if (check_character(my_map, x, y + 1, '0') || check_character(my_map, x, y + 1, 'C') || check_character(my_map, x, y + 1, 'E'))
				{
					if (move_check(my_map, x, y + 1))
						return ;
					my_map->map_arr[y + 1][x] = 'P';
					my_map->map_arr[y][x] = '0';
				}
			}
		}
	}
}

void    move_up(t_map *my_map)
{
        int     x;
        int     y;

        y = -1;
        while (++y < my_map->height_y)
        {
                x = -1;
                while (++x < my_map->width_x)
                {
                        if (my_map->map_arr[y][x] == 'P')
                        {
				printf("move up player location: %d %d\n", x, y);
                                if (check_character(my_map, x, y - 1, '0') || check_character(my_map, x, y - 1, 'C') || check_character(my_map, x, y - 1, 'E'))
                                {
					if (move_check(my_map, x, y - 1))
						return ;
                                        my_map->map_arr[y - 1][x] = 'P';
					my_map->map_arr[y][x] = '0';
                                }
                        }
                }
        }
}

void    move_left(t_map *my_map)
{
        int     x;
        int     y;

        y = -1;
        while (++y < my_map->height_y)
        {
                x = -1;
                while (++x < my_map->width_x)
                {
                        if (my_map->map_arr[y][x] == 'P')
                        {
                                if (check_character(my_map, x - 1, y, '0') || check_character(my_map, x - 1, y, 'C') || check_character(my_map, x - 1, y, 'E'))
                                {
					if (move_check(my_map, x - 1, y))
                                        	return ;
					my_map->map_arr[y][x - 1] = 'P';
                                        my_map->map_arr[y][x] = '0';
                                }
                        }
                }
        }
}

void    move_right(t_map *my_map)
{
        int     x;
        int     y;

        y = -1;
        while (++y < my_map->height_y)
        {
                x = -1;
                while (++x < my_map->width_x)
                {
                        if (my_map->map_arr[y][x] == 'P')
                        {
                                if (check_character(my_map, x + 1, y, '0') || check_character(my_map, x + 1, y, 'C') || check_character(my_map, x + 1, y, 'E'))
                                {
					if (move_check(my_map, x + 1, y))
						return ;
                                        my_map->map_arr[y][x + 1] = 'P';
                                        my_map->map_arr[y][x] = '0';
                                }
                        }
                }
        }
}

int	move_check(t_map *my_map, int x, int y)
{
	if (check_character(my_map, x, y, 'C'))
	{
		catch_collectable(my_map);
		return 0;
	}
	if (my_map->collected != my_map->count_c && check_character(my_map, x, y, 'E'))
	{
		return 1;
	}
	if (my_map->collected == my_map->count_c && check_character(my_map, x, y, 'E'))
		my_map->exit_open = 1;
	return 0;
}
