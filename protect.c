#include "so_long.h"

mlx_texture_t	*protect_text(mlx_texture_t *elem)
{
	if (!elem)
		ft_error("Texture cant be created");
	return (elem);
}

mlx_image_t	*protect_img(mlx_image_t *elem)
{
	if (!elem)
		ft_error("Image cant be created");
	return (elem);
}

void	protect_(int32_t elem)
{
	if (elem == -1)
		ft_error("Images cant be displayed on screen");
}
