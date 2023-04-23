#include "so_long.h"

/**
 * This function sets the key callback, which is called when a key is pressed
 * on the keyboard. Useful for single keypress detection.
 *
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The keypress callback function.
 * @param[in] param An additional optional parameter.
 */
//void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);

//typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);

/*
typedef enum action
{
    MLX_RELEASE = 0,
    MLX_PRESS   = 1,
    MLX_REPEAT  = 2,
}   action_t;
*/
/*
if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
            my_map->y_p_location++;
        if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
            my_map->x_p_location--;
        if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
            my_map->x_p_location++;
*/

void	mlx_key_hook_callback(mlx_key_data_t keydata, void *param)
{
//	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
//		mlx_close_window()
	set_key_up(keydata, (t_map*)param);	
}

void	set_key_up(mlx_key_data_t keydata, t_map *my_map)
{
   /* if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS){
        ft_printf("W\n");
    }*/
	if (my_map->map_arr[my_map->y_p_location - 1][my_map->x_p_location] != '1')
	{
		if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS){
            ft_printf("W\n");
	    		my_map->y_p_location--;
			my_map->graphs->bag_img->instances[0].y -= 64;

        }
		if (my_map->map_arr[my_map->y_p_location][my_map->x_p_location] == 'C')
		{
			my_map->count_c--;
		}
	}
}
