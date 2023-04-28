/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   protect.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 11:54:54 by gozturk       #+#    #+#                 */
/*   Updated: 2023/04/28 18:28:48 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*protect_mem(char *map)
{
	if (!map)
		ft_exit("Memory allocation");
	return (map);
}

mlx_texture_t	*protect_text(mlx_texture_t *elem)
{
	if (!elem)
		ft_exit("Texture cant be created");
	return (elem);
}

mlx_image_t	*protect_img(mlx_image_t *elem)
{
	if (!elem)
		ft_exit("Image cant be created");
	return (elem);
}

void	protect_(int32_t elem)
{
	if (elem == -1)
		ft_error("Images cant be displayed on screen");
}
