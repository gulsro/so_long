#include "so_long.h"

void	mlx_key_hook_callback(mlx_key_data_t keydata, void *param)
{
//	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//		mlx_close_window((mlx_t*)param->mlx);
//	find_player((t_map*)param);
//	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//		mlx_close_window((t_map*)param->(mlx_t*)mlx);
	t_map	*my_map;

	my_map = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
                mlx_close_window(my_map->mlx);
	if (my_map->exit_open == 0)
	{	
		set_key_up(keydata, my_map);	
		set_key_down(keydata, my_map);
		set_key_right(keydata, my_map);
		set_key_left(keydata, my_map);
	}
//	move_check(my_map);
}

void	set_key_up(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        {
                move_up(my_map);
        }
/*	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS
			&& check_character(my_map, my_map->x_p_location, my_map->y_p_location - 1, '1') == 0)
	{
		my_map->y_p_location--;
		my_map->graphs->bag_img->instances[0].y -= 64;
		if (check_character(my_map, my_map->x_p_location, my_map->y_p_location, 'C'))
		{
			catch_collectable(my_map, my_map->x_p_location, my_map->y_p_location);
        		my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		}
	}*/
}

void	set_key_down(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		move_down(my_map);		
	}
/*	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && check_character(my_map, my_map->x_p_location, my_map->y_p_location + 1, '1') == 0)
        {
		my_map->map_arr[my_map->y_p_location + 1][my_map->x_p_location] = 'P';
		my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		my_map->graphs->bag_img->instances[0].y += 64;
		if (check_character(my_map, my_map->x_p_location, my_map->y_p_location, 'C'))
		{	
			catch_collectable(my_map, my_map->x_p_location, my_map->y_p_location);
                	//my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		}
        }*/
}

void	set_key_right(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        {
                move_right(my_map);
        }
/*	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && check_character(my_map, my_map->x_p_location + 1, my_map->y_p_location, '1') == 0)
        {
		my_map->x_p_location++;
		my_map->graphs->bag_img->instances[0].x += 64;
		if (check_character(my_map, my_map->x_p_location, my_map->y_p_location, 'C'))
		{	
			catch_collectable(my_map, my_map->x_p_location, my_map->y_p_location);
                	my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		}
        }*/
}

void	set_key_left(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        {
                move_left(my_map);
        }
	/*
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && check_character(my_map, my_map->x_p_location - 1, my_map->y_p_location, '1') == 0)
        {
		my_map->x_p_location--;
		my_map->graphs->bag_img->instances[0].x -= 64;
		if (check_character(my_map, my_map->x_p_location, my_map->y_p_location, 'C'))
		{	
			catch_collectable(my_map, my_map->x_p_location, my_map->y_p_location);
                	my_map->map_arr[my_map->y_p_location][my_map->x_p_location] = '0';
		}
        }*/
}




