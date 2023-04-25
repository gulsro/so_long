#include "so_long.h"

void	move_down(t_map *my_map)
{
/*	int	x;
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
					my_map->graphs->bag_img->instances[0].y += 64;
					
					if (move_check(my_map, x, y + 1))
						return ;
					my_map->map_arr[y + 1][x] = 'P';
					my_map->map_arr[y][x] = '0';
				
				}
			}
		}
	}*/
	if (check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y + 1, '1') == 0)
	{	
//		my_map->map_arr[my_map->y_p_location + 1][my_map->x_p_location] = 'P';
//		my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		my_map->graphs->bag_y++;
		my_map->graphs->bag_img->instances[0].y += 64;
		move_check(my_map);
	}
}

void    move_up(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y - 1, '1') == 0)
        {
  //              my_map->map_arr[my_map->y_p_location - 1][my_map->x_p_location] = 'P';
    //            my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
                my_map->graphs->bag_y--;
		my_map->graphs->bag_img->instances[0].y -= 64;
        	move_check(my_map);
	}
	/*
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
        }*/
}

void    move_left(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x - 1, my_map->graphs->bag_y, '1') == 0)
        {
      //          my_map->map_arr[my_map->y_p_location][my_map->x_p_location - 1] = 'P';
        //        my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
                my_map->graphs->bag_x--;
		my_map->graphs->bag_img->instances[0].x -= 64;
        	move_check(my_map);
	}
	/*
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
        }*/
}

void    move_right(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x + 1, my_map->graphs->bag_y, '1') == 0)
        {
          //      my_map->map_arr[my_map->y_p_location][my_map->x_p_location + 1] = 'P';
            //    my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
                my_map->graphs->bag_x++;
		my_map->graphs->bag_img->instances[0].x += 64;
        	move_check(my_map);
	}
	/*
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
        }*/
}

void	move_check(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y, 'C'))
	{
		catch_collectable(my_map);
	}
	else if (my_map->collected != my_map->count_c && check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y, 'E'))
	{
		printf("LAAA");
	}
	else if (my_map->collected == my_map->count_c && check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y, 'E'))
		my_map->exit_open = 1;
		printf("LAAA");
}
