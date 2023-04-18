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
	char	*content;
	int	width_x;
	int	height_y;
	int	count_e;
	int	count_p;
	int	count_c;

}t_map;

//input_valid.c
//char	*append_line_to_map(char *map, char *line);
char	**make_map_arr(t_map   *t_map, int fd);
int		ft_strlen_protect(char *str);
int		open_file(char **argv);

//map_valid.c
void	map_scale(t_map *my_map);

//error_exit.c
void	ft_exit(char *error_msg, int exit_code);

#endif
