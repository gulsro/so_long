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

typedef struct s_map
{
	char 	**map_arr;
	char	**cpy_arr;
	int		width_x;
	int		height_y;
	int		count_c;
	int		x_p_location;
	int		y_p_location;

}t_map;

//input_valid.c
//char	*append_line_to_map(char *map, char *line);
void	make_map_arr(t_map   *t_map, int fd);
int		ft_strlen_protect(char *str);
int		open_file(char **argv);

//map_utils.c
void	map_scale(t_map *my_map);
//char	**create_map_arr_cpy(t_map *my_map);
void	create_map_arr_cpy(t_map *my_map);

//map_valid.c
int	check_walls(t_map  *my_map);
int	check_rectangular_map(t_map *my_map);
int	check_number_of_ecp(t_map *my_map);
int	check_all(t_map *my_map);

//walkable_path.c
int		is_walkable(t_map *my_map, int new_x, int new_y);
void	find_player(t_map *my_path);

//error_exit.c
void	ft_exit(char *error_msg, int exit_code);

#endif
