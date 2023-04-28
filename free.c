/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:39:38 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 11:40:30 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_arr(char **map_arr)
{
	int	i;

	i = 0;
	while (map_arr[i])
	{
		free(map_arr[i]);
		i++;
	}
	free(map_arr);
}
