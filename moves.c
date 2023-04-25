#include "so_long.h"

void	move_down(t_map *my_map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < my_map->width_x)
	{
		x = -1;
		while (++x < my_map->height_y)
		{
			if (my_map->map_arr[y][x] == 'P')
			{
				if (check_character(my_map, x, y + 1, '0') || check_character(my_map, x, y + 1, 'C') || check_character(my_map, x, y + 1, 'E'))
				{
					my_map->map_arr[y + 1][x] = 'P';
					my_map->map_arr[y][x] = '0';
					move_check(my_map);
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
        while (++y < my_map->width_x)
        {
                x = -1;
                while (++x < my_map->height_y)
                {
                        if (my_map->map_arr[y][x] == 'P')
                        {
                                if (check_character(my_map, x, y - 1, '0') || check_character(my_map, x, y - 1, 'C') || check_character(my_map, x, y - 1, 'E'))
                                {
                                        my_map->map_arr[y - 1][x] = 'P';
                                        my_map->map_arr[y][x] = '0';
                                        move_check(my_map);
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
        while (++y < my_map->width_x)
        {
                x = -1;
                while (++x < my_map->height_y)
                {
                        if (my_map->map_arr[y][x] == 'P')
                        {
                                if (check_character(my_map, x - 1, y, '0') || check_character(my_map, x - 1, y, 'C') || check_character(my_map, x - 1, y, 'E'))
                                {
                                        my_map->map_arr[y][x - 1] = 'P';
                                        my_map->map_arr[y][x] = '0';
                                        move_check(my_map);
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
        while (++y < my_map->width_x)
        {
                x = -1;
                while (++x < my_map->height_y)
                {
                        if (my_map->map_arr[y][x] == 'P')
                        {
                                if (check_character(my_map, x + 1, y, '0') || check_character(my_map, x + 1, y, 'C') || check_character(my_map, x + 1, y, 'E'))
                                {
                                        my_map->map_arr[y][x + 1] = 'P';
                                        my_map->map_arr[y][x] = '0';
                                        move_check(my_map, x + 1);
                                }
                        }
                }
        }
}

void	move_check(t_map *my_map, int x, int y)
{
	if (check_character(my_map, x, y, 'C'))
		catch_collectable(my_map, x, y);
	if (my_map->collected == my_map->count_c && check_character(my_map, x, y, 'E'))
		ft_printf("OPEN THE EXIT DOOR");
}
