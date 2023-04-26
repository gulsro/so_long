#include "so_long.h"

void	move_down(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y + 1, '1') == 0)
	{	
		my_map->graphs->bag_y++;
		my_map->graphs->bag_img->instances[0].y += 64;
		move_check(my_map);
	}
}

void    move_up(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x, my_map->graphs->bag_y - 1, '1') == 0)
        {
	  	my_map->graphs->bag_y--;
		my_map->graphs->bag_img->instances[0].y -= 64;
        	move_check(my_map);
	}
}

void    move_left(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x - 1, my_map->graphs->bag_y, '1') == 0)
        {
	      	my_map->graphs->bag_x--;
		my_map->graphs->bag_img->instances[0].x -= 64;
        	move_check(my_map);
	}
}

void    move_right(t_map *my_map)
{
	if (check_character(my_map, my_map->graphs->bag_x + 1, my_map->graphs->bag_y, '1') == 0)
        {
		my_map->graphs->bag_x++;
		my_map->graphs->bag_img->instances[0].x += 64;
        	move_check(my_map);
	}
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
