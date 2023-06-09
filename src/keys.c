/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keys.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:41:24 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 17:53:14 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	mlx_key_hook_callback(mlx_key_data_t keydata, void *param)
{
	t_map	*my_map;

	my_map = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(my_map->mlx);
		else if (keydata.key == MLX_KEY_W && my_map->exit_open == 0)
			move_up(my_map);
		else if (keydata.key == MLX_KEY_S && my_map->exit_open == 0)
			move_down(my_map);
		else if (keydata.key == MLX_KEY_D && my_map->exit_open == 0)
			move_right(my_map);
		else if (keydata.key == MLX_KEY_A && my_map->exit_open == 0)
			move_left(my_map);
	}
}
