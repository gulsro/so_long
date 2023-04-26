#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "lib/MLX42/include/MLX42/MLX42.h"

# include <libft.h>
# include <get_next_line.h>
# include <ft_printf.h>

typedef struct s_graphs
{
        mlx_texture_t   *bin_text;
        mlx_image_t             *bin_img;
        mlx_texture_t   *poop_text;
        mlx_image_t             *poop_img;
        mlx_texture_t   *grass_text;
        mlx_image_t             *grass_img;
        mlx_texture_t   *bag_text;
        mlx_image_t             *bag_img;
        mlx_texture_t   *wall_text;
        mlx_image_t             *wall_img;
	int			bag_x;
	int			bag_y;
	//        mlx_t                   *mlx;

}t_graphs;

typedef struct s_map
{
	char 	**map_arr;
	char	**cpy_arr;
	int		width_x;
	int		height_y;
	int		count_c;
	int		x_p_location;
	int		y_p_location;
	int		collected;
	int		exit_open;
	int		move;
	mlx_t	*mlx;
	t_graphs	*graphs;
}t_map;

//keys.c
void    mlx_key_hook_callback(mlx_key_data_t keydata, void* param);
void    set_key_up(mlx_key_data_t keydata, t_map *my_map);
void	set_key_down(mlx_key_data_t keydata, t_map *my_map);
void	set_key_left(mlx_key_data_t keydata, t_map *my_map);
void	set_key_right(mlx_key_data_t keydata, t_map *my_map);

//keys_utils.c
int     check_character(t_map *my_map, int x, int y, char character);
void    catch_collectable(t_map *my_map);

//moves.c
void    move_down(t_map *my_map);
void    move_up(t_map *my_map);
void    move_right(t_map *my_map);
void    move_left(t_map *my_map);
void	move_check(t_map *my_map);


//image.c
//void    make_image(mlx_t *mlx, t_graphs *graphs);
void	images_to_window(t_map *my_map);

//init_map.c
void    init_map_struct(t_map *my_map);
int    check_map(t_map *my_map, char **argv);

//input_valid.c
void	make_map_arr(t_map   *t_map, int fd);
int		ft_strlen_protect(char *str);
int		open_file(char *argv);

//map_utils.c
void	map_scale(t_map *my_map);
//char	**create_map_arr_cpy(t_map *my_map);
char	**create_map_arr_cpy(t_map *my_map);

//map_valid.c
int	check_walls(t_map  *my_map);
int	check_rectangular_map(t_map *my_map);
int	check_number_of_ecp(t_map *my_map);
int	check_all(t_map *my_map);

//walkable_path.c
int		is_walkable(t_map *my_map, int new_x, int new_y);
void	find_player(t_map *my_map);
char	**move(t_map *my_map, char **cpy_arr, int x_pos, int y_pos);
int     check_valid_chars_after_move(char **cpy_arr);

//error_exit.c
void	ft_exit(char *error_msg, int exit_code);

#endif
