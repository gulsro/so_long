#include "so_long.h"

void	mlx_key_hook_callback(mlx_key_data_t keydata, void *param)
{
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
}

void	set_key_up(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
        {
                move_up(my_map);
        }
}

void	set_key_down(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		move_down(my_map);		
	}
}

void	set_key_right(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
        {
                move_right(my_map);
        }
}

void	set_key_left(mlx_key_data_t keydata, t_map *my_map)
{
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
        {
                move_left(my_map);
        }
}




