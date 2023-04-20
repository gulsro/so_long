#include "so_long.h"

void	display_poop(mlx_t *mlx, t_graphs *graphs)
{
	uint32_t	i;
    uint32_t	j;
	
	i = 0;
	j = 0;
	//create a image buffer
	//	graphs->poop_img = mlx_new_image(mlx, 64, 64);
  //  if (!graphs->poop_img
    //    ft_exit("IMG struct cant be created", 1);
	while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            mlx_image_to_window(mlx, graphs->poop_img, (mlx->width)/2-(graphs->poop_img->width)/2, (mlx->height)/2-(graphs->poop_img->height)/2);
            j++;
        }
        i++;
	}
}

void    display_bag(mlx_t *mlx, t_graphs *graphs)
{
    uint32_t    i;
    uint32_t    j;

    i = 0;
    j = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            mlx_image_to_window(mlx, graphs->bag_img, (mlx->width)/2-(graphs->bag_img->width)/2, (mlx->height)/2-(graphs->bag_img->height)/2);
            j++;
        }
        i++;
    }
}

void	display_bin(mlx_t *mlx, t_graphs *graphs, t_map *my_map)
{
	uint32_t    i;
    uint32_t    j;

    i = 0;
    j = 0;
	while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            mlx_image_to_window(mlx, graphs->bin_img, my_map->x_p_location, my_map->y_p_location);
            j++;
        }
        i++;
    }
}

void    display_grass(mlx_t *mlx, t_graphs *graphs)
{
    uint32_t    i;
    uint32_t    j;

    i = 0;
    j = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            mlx_image_to_window(mlx, graphs->grass_img, (mlx->width)/2-(graphs->grass_img->width)/2, (mlx->height)/2-(graphs->grass_img->height)/2);
            j++;
        }
        i++;
    }
}

void    display_wall(mlx_t *mlx, t_graphs *graphs)
{
    uint32_t    i;
    uint32_t    j;

    i = 0;
    j = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            mlx_image_to_window(mlx, graphs->wall_img, (mlx->width)/2-(graphs->wall_img->width)/2, (mlx->height)/2-(graphs->wall_img->height)/2);
            j++;
        }
        i++;
    }
}
